
	switch (arg[0]) {
	case "y":
		set("y", arg[1]);
		return;
	break;
	case "tile":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 * Keep natural image size - don't stretch to pane size
		 */
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
		/* Not applicable for images - return 0 to trigger lbarConfig off */
		return 0;
	break;
	case "VW_event":
		/* arg[1] is VIEW_ON or VIEW_OFF */
		return;
	break;
	case "config":
		/* Delegate to C-level GIF config which handles image loading/resizing */
		config(arg[1], arg[2], arg[3], arg[4]);
		return;
	break;
	case "yP":
		return y();
	break;
	case "heightP":
		return height();
	break;
	case "build":
		/* arg[1]	sourcefile (URL)
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 *
		 * Download image, convert to GIF via ImageMagick, display
		 */
		docURL = arg[1];
		docName = arg[3];
		set("parent", arg[2]);
		set("name", docName);

		prevWidth = arg[4];
		prevHeight = send(parent(), "heightP");

		/* Download the source image */
		localSource = HTTPGet(docURL);
		if (isBlank(localSource) == 1) {
			cursorShape("idle");
			return 0;
		}

		/* Convert to GIF via ImageMagick */
		localFile = concat(localSource, ".gif");
		system(concat("magick '", localSource, "' -colors 256 '", localFile, "'"));

		/* Clean up source file */
		send("wwwSecurity", "rmTmpFile", localSource);

		set("width", 0);
		set("height", 0);
		set("label", localFile);
		cursorShape("idle");
		return get("name");
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 * Keep natural size - don't resize to viewer dimensions
		 */
		if (get("window")) raise();
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
