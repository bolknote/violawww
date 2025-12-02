
/*XXX this object is a mess
print("wwwHandlerDispatch: ");
for (i=0; i < arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("\n");
*/

	switch (arg[0]) {
	case "dispatch":
		/* arg[1]	handler
		 * arg[2]	doPost
		 * arg[3]	docURL
		 * arg[4]	docName
		 * arg[5]	paneObj
		 * arg[6]	paneWidth
		 * arg[7]	paneHeight
		 * arg[8]	anchor
		 * arg[9]	message user?
		 * arg[10]	postData
		 */
		handler = arg[1];
		doPost = arg[2];
		docURL = arg[3];
		docName = arg[4];
		paneObj = arg[5];
		paneWidth = arg[6];
		paneHeight = arg[7];
		anchor = arg[8];
		messageUserP = arg[9];
		postData = arg[10];

/*		print("SHOW: handler=", handler, 
				"; name=", docName, "\n");*/

		switch (handler) {
		case "VWHandler_html2":
			docObj = send(handler, 
					'B', docURL,
					paneObj, docName,
					paneWidth, anchor, doPost, postData);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}

/*
		print("wwwHandlerDispatch: calling docObj=", docObj, 
				"; paneWidth=", paneWidth, "\n");
*/
			send(docObj, 'T', 0, paneWidth);

			send(paneObj, "setChildren", docObj);

			if (anchor != "") {
				if (messageUserP) 
					www.mesg.tf("show", 
						"Going to anchor...");

				pageYPos = send(docName, "gotoAnchor", 
						anchor) * -1;
			} else {
				pageYPos = 0;
			}
			send(docName, "y", pageYPos);

			if (messageUserP) www.mesg.tf("show", "Rendering...");
			if (messageUserP) www.mesg.tf("clear");

			return docObj;
		break;
		case "VWHandler_html":
		case "VWHandler_hmml":
			docObj = send(handler, 
					'B', docURL,
					paneObj, docName,
					paneWidth, anchor);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}

			send(docObj, 'T', 0, paneWidth);

			send(paneObj, "setChildren", docObj);

			if (anchor != "") {
				if (messageUserP) 
					www.mesg.tf("show", 
						"Going to anchor...");

				pageYPos = send(docName, "gotoAnchor", 
						anchor) * -1;
			} else {
				pageYPos = 0;
			}
			send(docName, "y", pageYPos);

			if (messageUserP) www.mesg.tf("show", "Rendering...");

			send(docName, "show");

			tweak(docName, "raise();");
			/* questionable. will windoiw be created by now? */

			if (messageUserP) www.mesg.tf("clear");

			return docObj;
		break;
		case "VWHandler_hmmlb":

			/* inform the new page of: 
			 * 	sourcefile, parent, name, width
			 */
			docObj = send(handler, 
					'B', docURL,
					paneObj, docName,
					paneWidth, anchor);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}

			send(docObj, 'T', 0, paneWidth);

			send(paneObj, "setChildren", docObj);
			/*print("SHOW: HMML docObj=", docObj, "\n");*/
			if (anchor != "") {
				www.mesg.tf("show", 
					"Going to anchor...");
				pageYPos = send(docName, "gotoAnchor", 
						anchor) * -1;
			} else {
				pageYPos = 0;
			}
			send(docName, "y", pageYPos);

			www.mesg.tf("show", "Rendering...");

			send(docName, "show");
			tweak(docName, "raise();");

			if (messageUserP) www.mesg.tf("clear");
			return docObj;
		break;
		case "VWHandler_vobjf":
			docObj = VWHandler_vobjf("build", 
					docURL, docName, paneObj,
					paneWidth, paneHeight);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}

			send(paneObj, "setChildren", docObj);

			send(docObj, "visible", 1);

			send(docObj, "render");

			tweak(docObj, "raise();");

			send(docObj, "config", 
				0, 0, paneWidth, paneHeight);

			if (messageUserP) www.mesg.tf("clear");
			return docObj;
		break;
		case "VWHandler_plaintext":
		case "waisDB":
			/* inform the new page of: 
			 * 	sourcefile, parent, name, width
			 */
			docObj = send(handler, 
					"build", docURL,
					paneObj, docName, 
					paneWidth);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}
			send(docObj, "tile", 0, paneWidth, paneHeight);

			tweak(docObj, concat("set(\"parent\",\"",
						paneObj, "\");"));
			send(paneObj, "setChildren", docObj);

			send(docObj, "render");
			send(docObj, "raise");

			if (messageUserP) www.mesg.tf("clear");
			return docObj;
		break;
/*		case "VWHandler_xbm":
		case "VWHandler_xpm":
			* inform the new page of: 
			 * 	sourcefile, parent, name, width
			 *
			docObj = send(handler,
					"build", docURL,
					paneObj, docName, 
					paneWidth);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}

			send(docObj, "tile", 0, paneWidth, paneHeight);

			tweak(docObj, concat("set(\"parent\",\"",
						paneObj, "\");"));
			send(paneObj, "setChildren", docObj);

			send(docName, "render");

			if (messageUserP) www.mesg.tf("clear");
			return docObj;
		break;
*/
		case "VWHandler_gif":
		case "VWHandler_xbm":
		case "VWHandler_xpm":
			/* invoke xv or something...
			 * later, wrap this part into a 
			 * VWHandler_* object, so as not to 
			 * complicate it here
			 */
/*			DISP_METH = "inView";*/
			DISP_METH = "extView";

			switch (DISP_METH) {
			case "inView":
				docObj = send(handler,
						"build", docURL,
						paneObj, docName, 
						paneWidth);
				if (docObj == 0) return 0;

				send(docObj, "tile", 0, paneWidth, paneHeight);

				tweak(docObj, concat("set(\"parent\",\"",
							paneObj, "\");"));
				send(paneObj, "setChildren", docObj);

				send(docName, "render");

				if (messageUserP) www.mesg.tf("clear");
				return docObj;
			break;
			case "extView":
				localFile = HTTPGet(docURL);
				system(concat("xv ", localFile, " &"));
			break;
			}
			return 1;/*OK*/
		break;
		case "VWHandler_au":
			sourceFile = HTTPGet(docURL);

			/* Use macOS built-in afplay for audio playback */
			system(concat("/usr/bin/afplay ", sourceFile, " &"));
			return 1;/*OK*/
		break;
		case "VWHandler_pgp":
			sourceFile = HTTPGet(docURL);

print("VWHandlerDispatch: PGP: sourceFile={", sourceFile, "}\n");

			/* to fix: should not use absolute path to pgp
			 * 
			 */
			system(concat("cd /usr/users/pei/pgpTest/test;ls -al;/usr/local/bin/pgp ", sourceFile));
			newSourceFile = nthChar(sourceFile, 0, strlen(sourceFile) - 5);
print("VWHandlerDispatch: PGP: newSourceFile={", newSourceFile, "}\n");

			return send(self(), "dispatch", "VWHandler_html2",
				    arg[2], newSourceFile, arg[4], arg[5],
				    arg[6], arg[7], arg[8], arg[9], arg[10]);
		break;
		default:
			/*print("SHOW: Unknown handler, treat as plaintext: ",
				docName, "\n");*/

			/* inform the new page of: 
			 * 	sourcefile, parent, name, width
			 */
			docObj = send("plaintext", 
					"build", docURL,
					paneObj, docName, 
					paneWidth);
			if (docObj == 0) {
				if (messageUserP) www.mesg.tf("clear");
				return 0;
			}
			if (isBlank(docObj)) return 0;

			send(paneObj, "setChildren", docObj);

			send(docName, "render");

			if (messageUserP) www.mesg.tf("clear");
			return docObj;
		break;
		}
	break;
	}
	usual();
