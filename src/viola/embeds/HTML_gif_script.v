
	switch (arg[0]) {
	case "D":
		localFile = HTTPGet(get("label"));
		top = send(parent(), "findTop");
		url = send(top, "query_docURL");

		/* to get the gif in its natural dimension (lame) */
		set("width", 0);
		set("height", 0);

		set("label", localFile, url);
		send("wwwSecurity", "rmTmpFile", localFile);

		return get("height");
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "IMG");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("label", get("label"), url);
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
		ref = concat(url, "?", x0, ",", y0, ",", x1, ",", y1, ";");

		set("FGColor", "black");
		drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);
		drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);
		set("FGColor", "white");
		drawLine(x1, y1 - 5, x1, y1 + 5);
		drawLine(x1 + 5, y1, x1 - 5, y1);
		send(top, "follow_href", ref);
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
