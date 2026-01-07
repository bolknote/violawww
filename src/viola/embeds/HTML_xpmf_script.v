/*
 * HTML_xpmf_script.v - External XPM image handler
 *
 * Handles XPM (X PixMap) images loaded from external URLs (via SRC attribute).
 * The "f" suffix indicates "file" - external file loading.
 *
 * Features:
 *   - Downloads XPM from URL via HTTPGet()
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
 * Used when: <FIGURE TYPE="xpm" SRC="image.xpm">
 */
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "FIGDATA");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		set("label", get("label"));
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
		 * arg[6]	delayWidth
		 * arg[7]	delayHeight
		 * arg[8]	ismap
		 */
		style = SGMLGetStyle("HTML", "FIGDATA");
		set("y", arg[3] + style[0]);
		set("x", style[2]);
		set("parent", arg[1]);
		set("width", arg[2]);
		ismap = arg[8];

		send("www.mesg.tf", "show", "Retrieving image data...");

		localFile = HTTPGet(arg[4]);

		send("www.mesg.tf", "show", "Retrieving image data... Done.");

		if (arg[5] > 0) {
			after(arg[5], self(), "loadData", localFile);
			return 50; /*XXX*/
		} else {
			set("label", loadFile(localFile));
			send("wwwSecurity", "rmTmpFile", localFile);
			return height();
		}
	break;
	case "loadData":
		set("label", localFile);
		send("wwwSecurity", "rmTmpFile", localFile);
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
			top = send(parent(), "findTop");
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
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
