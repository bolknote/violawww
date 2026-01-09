
	switch (arg[0]) {
	case "y":
		set("y", arg[1]);
		return;
	break;
	case "tile":
		set("visible", 1);
		set("x", 0);
		set("y", arg[1]);
		return;
	break;
	case "vspan":
		return height();
	break;
	case "show":
		set("visible", 1);
		render();
		if (get("window")) raise();
		return;
	break;
	case "configSideBar":
		return 0;
	break;
	case "VW_event":
		return;
	break;
	case "config":
		if (width() != arg[3]) {
			loadDoc = 1;
		} else if (height() != arg[4]) {
			loadDoc = 1;
		} else {
			loadDoc = 0;
		}
		if (loadDoc == 1) {
			clearWindow();
			set("width", arg[3]);
			set("height", arg[4]);
			render();
		}
		return;
	break;
	case "yP":
		return y();
	break;
	case "heightP":
		return height();
	break;
	case "build":
		/* arg[1]	docURL
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 */
		docURL = arg[1];
		docName = arg[3];
		set("parent", arg[2]);
		set("name", docName);

		prevWidth = arg[4];
		prevHeight = send(parent(), "heightP");

		localFile = HTTPGet(docURL);
		data = loadFile(localFile);
		send("wwwSecurity", "rmTmpFile", localFile);

		if (isBlank(data) == 1) {
			cursorShape("idle");
			return 0;
		} else {
			set("label", data);
			set("width", prevWidth);
			set("height", prevHeight);
			cursorShape("idle");
			return get("name");
		}
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		if (get("window")) raise();
		return;
	break;
	case "historyRecord":
		wwwHistory("add", docName, docURL);
		return;
	break;
	case "reload":
		localPath = HTTPGet(docURL);
		data = loadFile(localPath);
		set("label", data);
		render();
		return;
	break;
	case "save":
		bell(1);
		return;
	break;
	case "queryAddress":
		return docURL;
	break;
	case "queryTitle":
		return docName;
	break;
	case "queryIsIndex":
		return 0;
	break;
	case "tree":
		return;
	break;
	case "showSrc":
		res.dialogWithButtons("show", 
				    concat("For source, please refer to:\n",
						 "docName: ", docName, 
						 "\nDoc URL: ", docURL),
					"OK", "");
		return;
	break;
	case "outlineSrc":
		return;
	break;
	case "print":
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
	case "raise":
		if (get("window")) raise();
		return;
	break;
	case "render":
		set("visible", 1);
		render();
		return;
	break;
	case "viewP":
		return 1;
	break;
	case "resize":
		return;
	break;
	case "clone":
		return clone(0);
	break;
	}
	usual();
