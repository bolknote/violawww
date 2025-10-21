
	switch (arg[0]) {
	case 'B':
		/* arg[1]	URL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * ret		documentObject or 0
		 */

		docName = arg[3];
		docObj = VWHandler_html.tf("clone");

		if (docObj == 0) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_html:\nfailed to clone, for: ", 
				arg[1], "\n"));
			return 0;
		}

		HTTPCurrentDocAddrSet(arg[1]);

		docObj = send(docObj,
				"build", arg[1], arg[2], arg[3], arg[4]);

		if (docObj == 0) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_html:\nfailed to access: ", 
				arg[1], "\n"));
			return 0;
		}

		return docObj;

		if (status == 0) {
			/* better destroy the useless clone */
			send(docObj, "freeSelf");
			return 0;
		} else {
			return docObj;
		}
	break;
	}
	usual();
