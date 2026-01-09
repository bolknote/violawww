
	switch (arg[0]) {
	case "build":
		/* arg[1]	sourcefile
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * ret		documentObject or 0
		 */
		docObj = VWHandler_xbm.xbm("clone");
		send(docObj, "build", arg[1], arg[2], arg[3], arg[4]);

		if (isBlank(docObj) == 1) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_xbm:\nfailed to access: ", 
				arg[1], "\n"));
			cursorShape("idle");
			return 0;
		} else {
			cursorShape("idle");
			return docObj;
		}
	break;
	}
	usual();
