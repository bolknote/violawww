
	switch (arg[0]) {
	case 'I':
		/* returns ID for new HMMLB Internal Object */
		objID = objID + 1;
		return concat("IObj_hmmlb", objID);
	break;
	case 'B':
		/* arg[1]	URL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * arg[5]	anchor
		 * ret		documentObject or 0
		 */

		if (arg[] < 5) {
			arg[4] = send("VWHandler_hmmlbb.doc.view", "widthP");
		}
/*
		print("################\n");
		print("##### HMMLB ####\n");
		print("################\n");
		print("############ building docObj ########\n");
		print("url='", arg[1], "'\n");
*/
		sourceFile = arg[1];
		localFile = HTTPGet(sourceFile);
		docName = arg[3];

		if (isBlank(localFile)) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_hmmlb:\nfailed to access: ", 
				sourceFile, "\n"));
			return 0;
		}

		HTTPCurrentDocAddrSet(sourceFile);

		docObj = SGMLBuildDocB(UNUSED,
			    localFile, arg[2], docName, arg[4], arg[5]);

		send(docObj, "nameAndURL", docName, arg[1]);
		tweak(docObj, concat("set(\"name\", \"", docName, "\");"));

		send("wwwSecurity", "rmTmpFile", localFile);
		return docName;
	break;
	case "out":
		for (i = 1; i < arg[]; i = i + 1) {
			print("#### ", arg[i]);
		}
		return;
	break;
	}
	usual();
