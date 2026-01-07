/*
 * HTML_giff_script.v - External GIF image handler
 *
 * Handles GIF images loaded from external URLs (via SRC attribute).
 * The "f" suffix indicates "file" - external file loading.
 *
 * Features:
 *   - Downloads GIF from URL via HTTPGet()
 *   - Supports delayed loading (MAYDELAY attribute)
 *   - Server-side image maps (ISMAP attribute)
 *   - Client-side image maps (FIGA hotspots)
 *
 * FIGA support messages:
 *   addFigA   - Creates an HTML_figa_actual child for each hotspot
 *   invertBox - Inverts a rectangular region (for hover effect)
 *   hintOn/Off - Shows/hides URL hint in status bar
 *   findTop   - Finds the top-level document for navigation
 *
 * Used when: <FIGURE TYPE="gif" SRC="image.gif">
 */
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		set("y", arg[1]);
		style = SGMLGetStyle("HTML", "FIGURE");
		vspan = style[0] + get("height") + style[1];
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	y
		 * arg[4]	docURL
		 * arg[5]	delayP
		 * arg[6]	delayWidth
		 * arg[7]	delayHeight
		 * arg[8]	ismap
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		set("y", arg[3]);
		ismap = arg[8];

		urlParts = HTTPCurrentDocAddrParsed(arg[4]);
		imgURL = concat(urlParts[0], "://", urlParts[1], 
				urlParts[2], urlParts[3]);

		/* to get the gif in its natural dimension */
		set("width", 0);
		set("height", 0);

		set("label", imgURL, imgURL);
		send("wwwSecurity", "rmTmpFile", localFile);

		return get("height");
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
	case "invertBox":
		invertRect(arg[1], arg[2], arg[3], arg[4]);
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
