
	switch (arg[0]) {
	case "render":
		set("visible", 1);
		render();
		raise();
		return;
	break;
	case "invoke":
		data = tweak(arg[1], "get(\"content\");");

		/* get rid of font-directive from likes of:
		 *	\f(7)telnet madlab.sprl.umich.edu\f(1) port \f(7)3000
		 */

		/* this is pretty messed up. remember to implement substr() */
		clearP = 1;
		while (clearP) {
			at = findPattern(data, "\\f");
			if (at == -1) clearP = 0;
			else {
				if (at == 1) {
					data = nthChar(data, 5, strlen(data));
				} else {
					data = concat(nthChar(data, 0, at - 2),
						nthChar(data, at + 4, 
							strlen(data)));
				}
			}
		}

		semiAt = findPattern(data, ";");
		if (semiAt == -1) {
			stmt = nthLine(data, 0);
			stmt = trimEdge(nthChar(stmt, 0, 999));
		} else {
			stmt = trimEdge(nthChar(data, 0, semiAt - 1));
		}
		print("stmt={", stmt, "}\n");

		switch (nthWord(stmt, 1)) {
		case "finger":
			tmp = makeTempFile();
			system(concat(stmt, " > ", tmp));
			set("visible", 1);
			render();
			deepObjectListSend("children", "render");
			raise();
			send(nthChild(1), "show", tmp);
			send(nthChild(0), "show", stmt);
			send("wwwSecurity", "rmTmpFile", tmp);
		break;
		case "telnet":
			/* can't handle this, pop up a shell */

			replaceCharQ(stmt, ';', '\0');
			p0 = findPattern(stmt, " port ");
			print(">>", stmt, "<<< p0=", p0, ".\n");

			if (p0 != -1) {
				/* Rid of "port", b/c it probably looks like:
				 * telnet eve.assumption.edu port 5000 
				 */

				port = nthChar(stmt, p0 + 6, 999);
				print(" port=>>>", port, "<<\n");

				hostName = nthWord(stmt, 2, 9);

				print(" hostname=>>>", hostName, "<<\n");

				print(">>", concat("xterm ", 
					"-title \"", hostName, "\" "),
					"-e ", stmt, " ", port, " &",
					"<<\n");
				system(concat("xterm ", 
					"-title \"", hostName, "\" ",
					"-e ", stmt, " ", port, " &"));
			} else {
				login = "";
				l0 = findPattern(stmt, "login");
				if (l0 != -1) {
					login = nthChar(stmt, l0 + 6, 999);
				}
				replaceCharQ(stmt, ';', '\0');
				replaceCharQ(stmt, '\\', '\0');
				hostName = nthWord(stmt, 2, 9);

				if (login) {
					print(">>", concat("xterm ", 
						"-title \"", hostName, "\" "),
						"-e ", stmt, " &",
						"<<\n");
					system(concat("xterm ", 
						"-title \"", hostName, "\" ",
						"-e ", stmt, " &"));
				} else {
					print(">>", concat("xterm ", 
						"-title \"", hostName, "\" "),
						"-e ", stmt,
						" -l ", login, " &",
						"<<\n");
					system(concat("xterm ", 
						"-title \"", hostName, "\" ",
						"-e ", stmt,
						" -l ", login, " &"));
				}
			}
			break;
		}
		return;
	break;
	case "finger":
		tmp = makeTempFile();
		system(concat("finger nasanews@space.mit.edu > ", tmp));
		send(nthChild(1), "show", tmp);
		send("wwwSecurity", "rmTmpFile", tmp);
		return;
	break;
	case "dismiss":
		set("visible", 0);
		return;
	break;
	}
	usual();
