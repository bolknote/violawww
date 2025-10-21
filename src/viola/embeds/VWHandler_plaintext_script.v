
	switch (arg[0]) {
	case "build":
		/* arg[1]	docURL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * ret		documentObject or 0
		 */
		docObj = VWHandler_plaintext.tf("clone");
		send(docObj, "build", arg[1], arg[2], arg[3], arg[4]);

		if (isBlank(docObj)) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_plaintext:\nfailed to access: ", 
				arg[1], "\n"));
			cursorShape("idle");
			return 0;
		} else {
			return docObj;
		}
	break;
	}
	usual();
