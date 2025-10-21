
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
		/* arg[1]	sourcefile
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
		if (isBlank(localFile) == 1) {
			www.mesg.tf("show", 
				    concatenate("Failed to get ", arg[1]));
			cursorShape("idle");
			return 0;
		} else {
			set("width", 0);
			set("height", 0);
			set("label", localFile);
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
		set("label", localFile);
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
/*
		VWHANDLER_GIF_EDITOR = "xv";
		system(concat(VWHANDLER_GIF_EDITOR, " ", localFile));
		set("label", localFile);
		render();
*/
		res.dialogWithButtons("show", 
				    concat("For source, please refer to:\n",
						 "docName: ", docName, 
						 "\nDoc URL: ", docURL),
					"OK", "");
		return;
	break;
	case "outlineSrc":
		www.mesg.tf("show", 
			    concatenate("Outliner not available for GIF\n"));
		return;
	break;
	case "print":
		www.mesg.tf("show", 
		    concat("Printing facillity not available for GIF.\n"));
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
		raise();
		return;
	break;
	case "clone":
		return clone(0);
	break;
	}
	usual();
