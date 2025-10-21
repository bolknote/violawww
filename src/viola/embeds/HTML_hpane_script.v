
	switch (arg[0]) {
	case "config":
		return;
	break;
	case "F": /* flush */
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			send(txtObj, "make", self(), 
				compressSpaces(get("label")),
				style_p[3], width() - style_p[3] - style_p[2],
				0, makeAnchor);
			makeAnchor = 0;
		}
		return -1;
	break;
	case "D":
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], width() - style_p[3] - style_p[2],
				0, makeAnchor);
			makeAnchor = 0;
		}
/*
		tagPtr = STG_tagPtr("HPANE");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (style == 0) style = SGMLGetStyle("HTML", "HPANE");
		vspan = style[0];
		config();
		n = countChildren();
		if (n) {
			xx = (get("width") - 10) / 2;
			cy = style[1];
			for (i = 0; i < n; i++) {
				h = send(nthChild(i), 'r');
				if (h > vspan) vspan = h;
			}
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "HPANE");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);
		config();
		n = countChildren();
		if (n) {
			xx = (get("width") - 10) / 2;
			cy = style[1];
			for (i = 0; i < n; i++) {
				h = send(nthChild(i), "r");
				if (h > vspan) vspan = h;
			}
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "r":
		if (style == 0) style = SGMLGetStyle("HTML", "HPANE");
		vspan = style[0];
		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "data":
		SGMLBuildDoc_setBuff(-1);
		return compressSpaces(get("label"));
	break;
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
				if (offset > 0) return offset + y();
			}
		}
		return 0;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "heightP":
		return get("height");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
