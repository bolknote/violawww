
	switch (arg[0]) {
	case "expose":
		if (label) drawText(35, 1, 1, label);
		return;
	break;
	case "D":
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
		set("content2", self());/*a kludge to deal with cloning*/
		if (canFold) {
			if (folded) {
				/* make the first list item go away,
				 * to show the toggler */
				send(nthChild(1), "R", 30, get("width"));
				send(nthChild(0), "setFolded", 1);
				return get("height") + 20;
			} else {
				return 20;
			}
		}
		if (style == 0) style = SGMLGetStyle("HTML", "OL");
		return get("height") + style[1];
	break;
	case "F":
		h = 0;
/*		SGMLBuildDoc_setBuff(-1);*/
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
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
		if (style == 0) style = SGMLGetStyle("HTML", "OL");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);

		if (foldInfo == 0) {
			send(self(), "reInit");
			if (label) drawText(35, 1, 1, label);
		}

		if (canFold) vspan += 18;
		if (canFold == 0 || folded == 0) {
			n = countChildren();
			if (n > canFold/*XXX warning: logic/numeral mix*/) {
				xx = get("width");
				for (i = canFold; i < n; i++)
				  vspan += send(nthChild(i), 'R', vspan, xx);
			}
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "OL");
		vspan = style[0];
		set("width", get("width") - style[3]);
		n = countChildren();
		if (n > canFold) {
			xx = get("width");
			for (i = canFold; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		vspan += style[1];
		return vspan;
	break;
	case "folded":
		if (foldInfo == 0) send(self(), "reInit");
		folded = arg[1];
		send(send(parent(), "findTop"), "resizeSelf");
		return;
	break;
	case "toggleFolded":
		if (foldInfo == 0) send(self(), "reInit");
		if (folded) folded = 0;
		else folded = 1;
		send(send(parent(), "findTop"), "resizeSelf");
		return folded;
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
		case "LABEL":
			label = arg[2];
		break;
		case "FOLD":
			canFold = 1;
			if (arg[2] == "yes" || arg[2] == "YES") folded = 1;
			set("BDColor", get("FGColor"));
			new = send("HTML__foldIcon", "make", self());
			set("children", new);
		break;
		case "BORDER":
			set("BDColor", "black");
		break;
		}
		return;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "compact":
		return compact;
	break;
	case "folded?":
		return folded;
	break;
	case "canFold?":
		return canFold;
	break;
	case "label?":
		return label;
	break;
	case "searchAnchor":
		if (tagID == arg[1]) return self();
		n = countChildren();
		if (n > canFold) {
			for (i = canFold; i < n; i++) {
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
		if (n > canFold) {
			for (i = canFold; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + get("y");
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
	case "findForm":
		return send(parent(), "findForm");
	break;
	case "reInit":
		/*HIGH KLUDGE-- to know if clone has occured*/
		foldInfo = 1;
		o = object(get("content2"));
		if (o) {
			canFold = send(o, "canFold?");
			folded = send(o, "folded?");
			label = send(o, "label?");
		}
		return;
	break;
	case "init":
		usual();
		foldInfo = 1;
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
