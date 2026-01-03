/*
 * HTML_psf_script.v - External PostScript image handler
 *
 * Handles PostScript images loaded from external URLs (via SRC attribute).
 * The "f" suffix indicates "file" - external file loading.
 *
 * Features:
 *   - Downloads PS from URL via HTTPGet()
 *   - Converts PS to GIF using ImageMagick (magick command)
 *   - Supports delayed loading (MAYDELAY attribute)
 *   - Supports custom WIDTH/HEIGHT for scaling
 *   - Server-side image maps (ISMAP attribute)
 *   - Client-side image maps (FIGA hotspots)
 *
 * FIGA support messages:
 *   addFigA   - Creates an HTML_figa_actual child for each hotspot
 *   invertBox - Inverts a rectangular region (for hover effect)
 *   hintOn/Off - Shows/hides URL hint in status bar
 *   findTop   - Finds the top-level document for navigation
 *
 * Used when: <FIGURE TYPE="ps" SRC="document.ps">
 */
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'R': /* resize */
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "FIGDATA");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		vspan += get("height") + style[1];
		render();
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	y
		 * arg[4]	src
		 * arg[5]	delayP
		 * arg[6]	width
		 * arg[7]	height
		 * arg[8]	ismap
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		style = SGMLGetStyle("HTML", "FIGDATA");
		set("y", style[0]);
		set("x", arg[3] + style[2]);
		ismap = arg[8];

		localSource = HTTPGet(arg[4]);
			
		localFile = concat(localSource, ".gif");

		w = int(arg[6]);
		h = int(arg[7]);

		if (w > 0 || h > 0) {
			if (w < 1) w = "";
			if (h < 1) h = "";

			resize = concat("-resize '", w, "x", h, "!' ");
		} else {
			resize = "";
		}

		system(concat("magick -density 80 -background white 'ps:",
			localSource, "' ", resize, "-alpha remove -alpha off -colors 256 '", 
			localFile,
		"'"));

		send("wwwSecurity", "rmTmpFile", localSource);

		if (arg[5] > 0) {
			after(arg[5], self(), 
				"loadData", localFile, arg[6], arg[7]);
			set("width", arg[6]);
			set("height", arg[7]);
		} else {
			/* to get the gif in its natural dimension */
			set("width", 0);
			set("height", 0);

			set("label", localFile);
		}
		return height();
	break;
	case "loadData":
		set("label", arg[1]);
		render();
		return;
	break;
	case "config":
		return;
	break;
	case "addFigA":
		new = send("HTML_figa_actual", "clone");
		send(new, "make", self(), 
			arg[1], arg[2], arg[3], arg[4], arg[5]);
		objectListAppend("children", new);
		return;
	break;
	case "hintOn":
		return send(parent(), "hintOn", arg[1]);
	break;
	case "hintOff":
		return send(parent(), "hintOff");
	break;
	case "invertBox":
		invertRect(arg[1], arg[2], arg[3], arg[4]);
		return;
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "gotoAnchor":
		return "";
	break;
	case "buttonPress":
		if (ismap) {
			xy = mouseLocal();
			x0 = xy[0];
			y0 = xy[1];
			set("FGColor", "black");
			drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);
			drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);
			set("FGColor", "white");
			drawLine(x0, y0 - 5, x0, y0 + 5);
			drawLine(x0 + 5, y0, x0 - 5, y0);
		}
	break;
	case "buttonRelease":
		if (ismap) {
			xy = mouseLocal();
			x1 = xy[0];
			y1 = xy[1];
			if (top == 0) top = send(parent(), "findTop");
			ref = concat(send(top, "query_docURL"), "?",
					x0, ",", y0, ",", x1, ",", y1, ";");

			set("FGColor", "black");
			drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);
			drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);
			set("FGColor", "white");
			drawLine(x1, y1 - 5, x1, y1 + 5);
			drawLine(x1 + 5, y1, x1 - 5, y1);
			send(top, "follow_href", ref);
		}
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "freeSelf":
		if (isBlank(localFile) == 0) {
			send("wwwSecurity", "rmTmpFile", localFile);
		}
		return;
	break;
	}
	usual();
