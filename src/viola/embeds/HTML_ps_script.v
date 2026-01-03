/*
 * HTML_ps_script.v - Inline PostScript image handler
 *
 * Handles PostScript images with inline data provided via <FIGDATA>.
 * PS data is saved to a temporary file and converted to GIF via ImageMagick.
 *
 * Features:
 *   - Saves PS data to temp file and converts via ImageMagick
 *   - Supports client-side image maps (FIGA hotspots)
 *   - Server-side image maps (ISMAP attribute)
 *
 * FIGA support messages:
 *   addFigA   - Creates an HTML_figa_actual child for each hotspot
 *   invertBox - Inverts a rectangular region (for hover effect)
 *   hintOn/Off - Shows/hides URL hint in status bar
 *   findTop   - Finds the top-level document for navigation
 *
 * Used when: <FIGURE TYPE="ps"><FIGDATA>...PS data...</FIGDATA></FIGURE>
 *
 * Requires: ImageMagick 'magick' command in PATH
 */
	switch (arg[0]) {
	case "D":
		return get("height");
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "FIGURE");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		vspan += get("height") + style[1];
		render();
		return vspan;
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
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	h
		 * arg[4]	label (PS data)
		 * arg[5]	ismap
		 */
		set("parent", arg[1]);
		targetW = arg[2];
		targetH = arg[3];
		ismap = arg[5];

		/* Save PS data to temporary file with BoundingBox header */
		localSource = concat("/tmp/viola_ps_", random(), ".ps");
		/* Prepend BoundingBox if WIDTH/HEIGHT specified */
		if (targetW > 0 && targetH > 0) {
			psWithBB = concat("%!PS-Adobe-2.0 EPSF-2.0\n%%BoundingBox: 0 0 ",
				targetW, " ", targetH, "\n",
				arg[4]);
			saveFile(localSource, psWithBB);
		} else {
			saveFile(localSource, arg[4]);
		}

		/* Convert PS to GIF via ImageMagick */
		localFile = concat(localSource, ".gif");
		system(concat("magick -density 72 -background white 'eps:",
			localSource, "' -alpha remove -alpha off -colors 256 '", 
			localFile, "'"));

		/* Clean up PS source file */
		send("wwwSecurity", "rmTmpFile", localSource);

		/* Load the converted GIF */
		set("width", 0);
		set("height", 0);
		set("label", localFile);

		return get("height");
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

