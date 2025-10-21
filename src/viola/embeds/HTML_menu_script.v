
	switch (arg[0]) {
	case "F": /* flush */
		h = 0;
		if (isBlank(get("label")) == 0) {
			if (style_li == 0)
				style_li = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			y = SGMLBuildDoc_span();
			h = send(txtObj, "make", self(), get("label"),
				style_li[2], 
				get("width") - style_li[2], y, 'M');
		} 
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D": /* done */
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style_li == 0)
				style_li = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			y = get("height");
			h += send(txtObj, "make", self(), get("label"),
				style_li[2], 
				get("width") - style_li[2], y, 'M');
		} 
		set("height", h);
		return get("height");
	break;
	case 'L':
		return 'M';
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "MENU");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);

		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}

		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "data":
		SGMLBuildDoc_setBuff(-1);
		return get("label");
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		}
	break;
	case "compact":
		return 1;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
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
		if (tagID == arg[1]) return get("y");
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + get("y");
			}
		}
		return 0;
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
