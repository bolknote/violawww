
	switch (arg[0]) {
	case "y":
		set("y", arg[1]);
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
/*
			data = loadFile(arg[1]);
			set("label", data);
			send(parent(), "update", vspan);
			vspan = get("height");
			parentHeight = send(parent(), "heightP");
			if (vspan >= parentHeight) {
				set("height", vspan);
			} else {
				set("height", parentHeight);
			}
*/
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
			www.mesg.tf("show", 
				    concat("Failed to get ", docURL));
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
		raise();
		if (arg[1] != prevWidth) {
			prevWidth = arg[1];
			set("width", prevWidth);
		} else if (arg[2] != prevHeight) {
			prevHeight = arg[2];
			set("height", prevHeight);
		}
		return;
	break;
	case "historyRecord":
		wwwHistory("add", docName, docURL);
		return;
	break;
	case "reload":
		localPath = HTTPGet(docURL);
		set("label", loadFile(localPath));
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
		/* produce a n-level anchors tree by recursively fetching
		 * anchor links 
		 */
		return;
	break;
	case "showSrc":
		VWHANDLER_XBM_EDITOR = "bitmap";
		tmp = concatenate(makeTempFile(), ".xbm");
		saveFile(tmp, get("label"));
		system(concatenate(VWHANDLER_XBM_EDITOR, " ", tmp));
		set("label", loadFile(tmp));
		render();
		send("wwwSecurity", "rmTmpFile", tmp);
		return;
	break;
	case "outlineSrc":
		www.mesg.tf("show", 
			"Outliner not available for VWHANDLER_XBM\n");
		return;
	break;
	case "cycleColors":
		cycleColors(1);
		render();
		return;
 	break;
	case "reverseVideo":
		cycleColors(1);
		cycleColors(1);
		render();
		return;
	break;
	case "colorsBGFGBD":
		set("BGColor", arg[1]);
		set("FGColor", arg[2]);
		set("BDColor", arg[3]);
		render();
		return;
 	break;
	case "torn":
		isTorn = 1;
		return;
	break;
	case "raise":
		raise();
		return;
	break;
	case "clone":
		return clone(0);
	break;
	case "init":
		usual();
		color = getResource("Viola*background");
		if (color) {
			set("BGColor", color);
		}
		color = getResource("Viola*foreground");
		if (color) {
			set("BDColor", color);
			set("FGColor", color);
		}
	break;
	}
	usual();
