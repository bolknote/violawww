
	switch (arg[0]) {
	case "expose":
		if (label) drawText(35, 1, 1, label);
		return;
	break;
	case "config":
		return;
	break;
	case "inAnchor":
	case "compact":
	case "L":
		return 0;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "D":
		set("content2", self());/*a kludge to deal with cloning*/
		h = get("height");
		SGMLBuildDoc_setBuff(0);/* necessary ...*/
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
				h, makeAnchor);
			makeAnchor = 0;
		}
		if (canFold && folded) {
			/* make the first list item go away,
			 * to show the toggler */
			send(nthChild(1), "R", 30, get("width"));
			send(nthChild(0), "setFolded", 1);
			set("height", 20);
			return 20;
		}
		set("height", h);
		return h;
	break;
	case "F":
		h = 0;
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
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "SECTION");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		if (foldInfo == 0) {
			send(self(), "reInit");
			if (label) drawText(35, 1, 1, label);
		}

		if (canFold) vspan += 18;
		if (canFold == 0 || folded == 0) {
			n = countChildren();
			if (n > canFold) {
				xx = get("width");
				for (i = canFold; i < n; i++)
				  vspan += send(nthChild(i), "R", vspan, xx);
			}
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
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
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
	case "folded?":
		return folded;
	break;
	case "canFold?":
		return canFold;
	break;
	case "label?":
		return label;
	break;
	case "setAnchor":
		makeAnchor = arg[1];
		return;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "editMode":
		editMode = arg[1];
		n = countChildren();
		if (n > canFold) {
			for (i = canFold; i < n; i++) {
				anchor = send(nthChild(i), 
						"editMode", editMode);
			}
		}
		return;
	break;
	case "AI":
	case "noBullet":
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
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
		}
		return;
	break;
	case "data":
		return compressSpaces(get("label"));
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
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "placeID":
		/* this is clumsy. should be simplified with a primitive f() */
		/* find the caller (child) object's place in the obj list */
		cobj = arg[1];
		objPlace = -1;

		for (i = objectListCount_children() - 1; i >= 0; i--) {
			nobj = nthChild(i);/*bug: can't inline into == XXX*/
			if (cobj == nobj) {
				objPlace = i;
			}
		}
		objPlacePath = concat(objPlace, " ", arg[2]);
		return send(parent(), "placeID", self(), objPlacePath);
	break;
	case "edit_gotoPrev":
		cobj = arg[1];
		objPlace = -1;
		for (i = objectListCount_children() - 1; i >= 0; i--) {
			nobj = nthChild(i);/*bug: can't inline into == XXX*/
			if (cobj == nobj) {
				objPlace = i;
			}
		}
		send(nthChild(objPlace-1), "edit_focus");
		return;
	break;
	case "edit_gotoNext":
		cobj = arg[1];
		objPlace = -1;

		for (i = objectListCount_children() - 1; i >= 0; i--) {
			nobj = nthChild(i);/*bug: can't inline into == XXX*/
			if (cobj == nobj) {
				objPlace = i;
			}
		}
/*
	if no next child, ask parent to goto next (then down to
	suitable editable element)...
print("CCCCCCCCCC objPlace=", objPlace, "\n");
print("CCCCCCCCCC o(objPlace)=", nthChild(objPlace), "\n");
print("CCCCCCCCCC o(objPlace+1)=", nthChild(objPlace+1), "\n");
*/

		send(nthChild(objPlace+1), "edit_focus");
		return;
	break;
	case "CE_change":
		return send(nthChild(nthWord(arg[1], 1)), arg[0],
				nthWord(arg[1], 2, 99), arg[2]);
	break;
	case "CE_lock":
	case "CE_unlock":
		return send(nthChild(nthWord(arg[1], 1)), arg[0],
				nthWord(arg[1], 2, 99));
	break;
	case "outputSGML":
		print("<SECTION>\n");
		n = countChildren();
		if (n) for (i = 0; i < n; i++)
				send(nthChild(i), "outputSGML");
		print("</SECTION>\n");
		return;
	break;
	case "setStyles":
		tagPtr = STG_tagPtr("SECTION");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
			i = STG_attr(tagPtr, "border");
			if (i) {
				set("border", 6);
				set("BDColor", get("FGColor"));/*XXX*/
			}
		}
		return;
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
