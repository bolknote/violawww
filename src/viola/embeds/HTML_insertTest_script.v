
	switch (arg[0]) {
	case "F":
		container = HTML_insertee("clone");
		w = width() - 40;
		y = SGMLBuildDoc_span();
		send(container, "make", self(), 30, y, w);
		SGMLBuildDoc_insertObj(container, w);

		return -1;
	break;
	case "D":
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style == 0) style = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style[3], width() - style[3] - style[2],
				h, makeAnchor);
			makeAnchor = 0;
		}
		set("height", h);
		return h;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "SECTION");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "SECTION");
		vspan = style[0];
		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "AI":
	case "noBullet":
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
			tagID = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		}
		return;
	break;
	case "data":
/*		SGMLBuildDoc_setBuff(-1);*/
		return compressSpaces(get("label"));
	break;
	case "searchAnchor":
		if (tagID == arg[1]) return self();
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				anchor = send(nthChild(i), 
						"searchAnchor", arg[1]);
				if (anchor != "") return anchor;
			}
		}
		return "";
	break;
	case "gotoAnchor":
		if (tagID == arg[1]) return y();
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + y();
			}
		}
		return 0;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	}
	usual();
