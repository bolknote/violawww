
	switch (arg[0]) {
	case "D":
		if (style == 0) style = SGMLGetStyle("HTML", "OLC");
		numStyle = 0;
		listDepthVal = send(parent(), "listDepth") + 1;
		tagPtr = STG_tagPtrDepth("LI", "OL", listDepthVal);
		if (tagPtr) {
			numStyle = STG_attr(tagPtr, "numStyle");
		}
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				itemN++;
				if (numStyle == "roman") {
					itemLabel = intToRoman(itemN);
				} else if (numStyle == "alpha") {
					itemLabel = intToAlpha(itemN);
				} else {
					itemLabel = itemN;
				}
				send(nthChild(i), "itemN", itemLabel);
			}
		}
		return height() + style[1];
	break;
	case "F":
		h = 0;
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], width() - style_p[3] - style_p[2],
				SGMLBuildDoc_span(), makeAnchor);
			makeAnchor = 0;
		}
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case 'L':
		return 'O';
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "OLC");
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
		if (style == 0) style = SGMLGetStyle("HTML", "OLC");
		vspan = style[0];
		set("width", width() - style[3]);
		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		vspan += style[1];
		return vspan;
	break;
	case "data":
		return get("label");
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
			tagID = arg[2];
		break;
		case "COMPACT":
			compact = 1;
		break;
		case "BORDER":
			set("BDColor", "black");
		break;
		}
		return;
	break;
	case "compact":
		return 1;
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
	case "listDepth":
		return send(parent(), "listDepth") + 1;
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
