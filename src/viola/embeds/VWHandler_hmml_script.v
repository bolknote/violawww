
	switch (arg[0]) {
	case 'I':
		/* returns ID for new HMML Internal Object */
		objID = objID + 1;
		return concat("IObj_hmml", objID);
	break;
	case 'B':
		/* arg[1]	URL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * arg[5]	anchor
		 * ret		documentObject or 0
		 */
/*
		print("################\n");
		print("##### HMML #####\n");
		print("################\n");
*/
		sourceFile = arg[1];
		localFile = HTTPGet(sourceFile);
		docName = arg[3];
/*
		print("sourceFile='", sourceFile, "'\n");
		print("localFile='", localFile, "'\n");
*/
		if (localFile == 0) {
			send("VWHandler_fail", "report", 
	   concat("VWHandler_hmml:\nfailed to fetch source : ", sourceFile));
			return 0;
		}
		if (arg[] < 5) {
			arg[4] = send("VWHandler_hmml.doc.view", "widthP");
		}
/*
		print("1 tmpFile=", tmpFile, "\n");
		print("1 sourceFile = {", sourceFile, "}\n");
*/
		tmpFile = makeTempFile();

		stat = system(concat(sgmlsA2BPath, " HMML ", localFile, 
					" > ", tmpFile));

/*		print("stat=", stat, "\n");*/

/*		system(concat("rm -f ", localFile));*/

		if (stat == -1) {
			send("VWHandler_fail", "reason", 
		   concat("VWHandler_hmml:\nFailed to convert document from HMML to HMMLB.\n",
"onsgmls not found. Install OpenSP: brew install open-sp (macOS) or apt-get install opensp (Linux)"));

			return 0;
		}
/*
		print("2 tmpFile=", tmpFile, "\n");
		print("2 localFile = {", localFile, "}\n");
		print("2 sourceFile = {", sourceFile, "}\n");
		print("############ building docObj ########\n");
		print("url='", arg[1], "'\n");
*/
		HTTPCurrentDocAddrSet(sourceFile);

		docObj = SGMLBuildDocB(UNUSED,
			    tmpFile, arg[2], docName, arg[4], arg[5]);

		send(docObj, "nameAndURL", docName, sourceFile);

		tweak(docObj, concat("set(\"name\", \"", docName, "\");"));

		send("wwwSecurity", "rmTmpFile", tmpFile);

		return docName;
	break;
	case "out":
		for (i = 1; i < arg[]; i = i + 1) {
			print("#### ", arg[i]);
		}
		return;
	break;
	case "init":
		/* Path to sgmlsA2B converter (converts SGML to binary format)
		 * sgmlsA2B internally uses onsgmls from OpenSP package
		 * macOS: brew install open-sp
		 * Linux: apt-get install opensp
		 *
		 * Uses VIOLA_SGMLSA2B env var if set, otherwise "sgmlsA2B" in PATH
		 */
		sgmlsA2BPath = environVar("VIOLA_SGMLSA2B");
		if (isBlank(sgmlsA2BPath)) {
			sgmlsA2BPath = "sgmlsA2B";
		}
	break;
	}
	usual();
