
/*
print("VWHandler_plaintext.tf: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");print("...end\n");
*/
	switch (arg[0]) {
	case "shownPositionV":
		return set("shownPositionV", arg[1]);
	break;
	case "tile":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		if (width() != arg[2]) {
			loadDoc = 1;
		} else if (height() != arg[3]) {
			loadDoc = 1;
		} else {
			loadDoc = 0;
		}
		if (loadDoc == 1) {
			set("y", arg[1]);

			prevWidth = arg[2];
			prevHeight = arg[3];
			set("width", arg[2]);
			set("height", arg[3]);
			render();
		}
		return;
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		set("visible", 1);
		set("width", arg[1]);
		set("height", arg[2]);
		render();
		return;
	break;
	case "resize":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		set("width", arg[1]);
		set("height", arg[2]);
		return;
	break;
	case "buttonRelease":
		if (charButtonMask() > 0) {
			/* has pressed inside a ``button'' */
			tag = nextTag();
			if (tag) {
				if (nthChar(tag, 1) == '*') {
					interpret(tag);
				} else {
					www("raise");
					if (www("show", tag))
						www("historyRecord");
				}
			} else {
				bell();
				www.mesg.tf("warn", 
				    "Try clicking the ending parts.");
			}
		} else {
			/* lets user complete cut/paste */
		}
		return;
	break;
	case "yP":
		return get("y");
	break;
	case "heightP":
		return get("height");
	break;
	case "vspan":
		return vspan;
	break;
	case "build":
		/* arg[1]	docURL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 */
		docURL = arg[1];
		localFile = HTTPGet(docURL);
		docName = arg[3];

		set("parent", arg[2]);
		set("name", docName);

		if (localFile == 0) {
			send("VWHandler_fail", "report", 
   concat("VWHandler_plaintext:\nfailed to fetch source : ", docURL));
			return 0;
		}
		addrInfo = HTTPCurrentDocAddrParsed(docURL);

		if (accessible(localFile) == 0) {
			send("VWHandler_fail", "report", 
				concat("Unable to find (local) file: ",
					localFile));
			return 0;
		}

		if (arg[] < 5) {
			arg[4] = send("VWHandler_hmml.doc.view", "widthP");
		}
		set("width", arg[4]);
		data = loadFile(localFile);
		if (isBlank(data) == 1) {
			send("VWHandler_fail", "report", 
   concat("VWHandler_plaintext:\nfailed to get: ", arg[1]));
			return 0;
		} else {
			set("content", data);
			render();
			data = 0;/* clear variable*/
			vspan = building_vspan();
			return docName;
		}
	break;
	case "historyRecord":
		wwwHistory("add", docURL, docURL); 
		return;
	break;
	case "reload":
		set("content", loadFile(docURL));
		render();
		return;
	break;
	case "search":
		cursorShape("busy");
		search(arg[1]);
		cursorShape("idle");
		return;
	break;
	case "keyPress":
		return;
	break;
	case "save":
		tmp = "/tmp/out.VWHandler_plaintext";
		saveFile(tmp, get("content"));
		cmd = concat("lpr ", tmp);
		system(cmd);
		return;
	break;
	case "queryAddress":
		return docURL;
	break;
	case "queryTitle":
		return docURL;
	break;
	case "queryIsIndex":
		return 0;
	break;
	case "tree":
		/* produce a n-level anchors tree by recursively fetching
		 * anchor links 
		 */
		return;
	break;
	case "showSrc":
		wwwSrc("showByURL", docURL);
		return;
	break;
	case "output2File":
		res.getLineEntry("show", 
			"Enter file name to save to document source to:", 
				"/tmp/out.txt",
				self(), "gotOutputFileName");
		return;
 	break;
	case "gotOutputFileName":
		dumpFile = HTTPGet(docURL);
		system(concat("mv ", dumpFile, " ", arg[1]));
		www.mesg.tf("show", 
			concat("Source saved to file: ", arg[1], "\n"));
		return;
 	break;
	case "outlineSrc":
		www.mesg.tf("show",
		  "Outliner not available for VWHandler_plaintext\n");
		return;
	break;
	case "print":
		tmp = "/tmp/out.txt";
		saveFile(tmp, get("content"));
		lprCmd = environVar("WWW_LPR");
		cmd = concat(lprCmd, tmp);
		system(cmd);
		www.mesg.tf("flash", concat("Printing command: ", cmd));
		send("wwwSecurity", "rmTmpFile", tmp);
		return;
 	break;
	case "torn":
		isTorn = 1;
		return;
	break;
	case "enter":
		set("cursor", 0); 
		return;
	break;
	case "render":
		return set("visible", 1);
	break;
	case "VIEW_ON":
	case "VIEW_OFF":
		return;
	break;
	case "raise":
		if (get("window")) raise();
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		color = getResource("Viola.background_doc");
		if (color) {
			set("BDColor", color);
			set("BGColor", color);
		}
		color = getResource("Viola.foreground_doc");
		if (color) set("FGColor", color);
	break;
	}
	usual();
