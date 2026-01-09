
	switch (arg[0]) {
	case "build":
		/* arg[1]	URL		
		 * arg[2]	doc name	(internal ref)
		 * arg[3]	parent
		 * arg[4]	width
		 * arg[5]	height
		 */
		n = n + 1;
		return send(clone(n), "make", 
				arg[1], arg[2], arg[3], arg[4], arg[5]);
	break;
	case "render":
		usual();
		objectListSend("children", "render");
		return;
	break;
	case "make":
		docURL = arg[1];
		docName = arg[2];

		/* Security: Set current address to actual URL before loading
		 * This ensures loadObjFile knows the real source of the file
		 */
		HTTPCurrentDocAddrSet(docURL);

		localFile = HTTPGet(docURL);

		addrInfo = HTTPCurrentDocAddrParsed(localFile);

		if (nthChar(addrInfo[2], 0) == '/') {
			path = addrInfo[2];
		} else {
			path = concat("/", addrInfo[2]);
		}
		objFileName = addrInfo[3];

		addrInfo = HTTPCurrentDocAddrParsed(docURL);
		objName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);

		stat = loadObjFile(path, objFileName);

		send("wwwSecurity", "rmTmpFile", localFile);

		if (stat <= 0) {
			print("failed to load obj file {", objFileName,
				"} in {", path, "}\n");
			
			new = send("HMML_fail", "clone");
			set("children", new);
			vspan = send(new, "make", self(), width(),
				     concat("Insert failed here: ", docURL));
			return vspan;
		}
		send(objName, "init");
		set("children", objName);

		set("name", docName);
		set("parent", arg[3]);
		set("width", arg[4]);
		set("height", arg[5]);

		tweak(objName, concat("set(\"parent\",\"", self(), "\");"));

		return self();
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		raise();
		set("width", arg[1]);
		set("height", arg[2]);
		return;
	break;
	case "resize":
		/* to change window sizes */
		set("width", arg[1]);
		set("height", arg[2]);

		/* to trigger geometry manager */
		send(self(), "config", 0, 0, arg[1], arg[2]);

		return;
	break;
	case "vspan":
		return 0;
	break;
	case "queryAddress":
		return docURL;
	break;
	case "queryTitle":
		return nthChild(0);
	break;
	case "queryIsIndex":
		return 0;
	break;
	case "historyRecord":
		wwwHistory("add", nthChild(0), docURL);
		return;
	break;
	case "reload":
		print("reload for *.v format not yet implemented\n");
		return;
	break;
	}
	usual();
