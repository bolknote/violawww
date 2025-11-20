
	switch (arg[0]) {
	case "D":
		set("label", get("label"));
		return get("height");
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "XBM");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		set("content", get("content"));
		vspan += get("height") + style[1];
		render();
		return vspan;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "buttonPress":
		xy = mouseLocal();
		x0 = xy[0];
		y0 = xy[1];
		set("FGColor", "black");
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);
		set("FGColor", "white");
		drawLine(x0, y0 - 5, x0, y0 + 5);
		drawLine(x0 + 5, y0, x0 - 5, y0);
	break;
	case "buttonRelease":
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
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	h
		 * arg[4]	label (XBM data)
		 * arg[5]	ismap
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		set("label", arg[4]);
		ismap = arg[5];
		return get("height");
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
