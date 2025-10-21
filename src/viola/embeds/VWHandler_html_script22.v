
	switch (arg[0]) {
	case 'B':
		/* arg[1]	URL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 * arg[5]	anchor
		 * arg[6]	doPost
		 * arg[7]	postData
		 * ret		documentObject or 0
		 */
		doPost = arg[6];
		sourceFile = arg[1];
		docName = arg[3];

		send("www.mesg.tf", "show", "Connecting to data provider...");

		if (doPost) {
			docObj = HTTPPost(sourceFile, arg[2], arg[4], arg[7]);
		} else {
			docObj = HTTPGetNParse(sourceFile, arg[2], arg[4]);
		}

		if (exist(docObj) == 0) {
			send("VWHandler_fail", "report", 
			  concat("VWHandler_html2:\nfailed to access: ", 
				sourceFile, "\n"));
			return 0;
		}

		docName = trimEdge(docName);

		send(docObj, "nameAndURL", docName, sourceFile);

		tweak(docObj, concat("set(\"name\", \"", docName, "\");"));

		return docName;
	break;
	case "out":
		for (i = 1; i < arg[]; i++) print("#### ", arg[i]);
		return;
	break;
	}
	usual();
