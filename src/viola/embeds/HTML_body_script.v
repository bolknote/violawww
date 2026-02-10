
/*
print("HTML_BODY: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");print("...end\n");
*/
	switch (arg[0]) {
	case "expose":
	case "config":
		return;
	break;
	case "F": /* flush */
		h = 0;
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(), 
				compressSpaces(get("label")), 
				style_p[2], 
				get("width") - style_p[2] - style_p[3],
				SGMLBuildDoc_span() + style_p[0],
				makeAnchor) + style_p[1];
			makeAnchor = 0;
		}
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D": /* done */
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone", self());
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[2], 
				get("width") - style_p[2], 
				h, makeAnchor);
			makeAnchor = 0;
		}
		set("height", h);
		return h;
	break;
	case "data":
		SGMLBuildDoc_setBuff(-1);
		return compressSpaces(get("label"));
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "BODY");
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
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "BODY");
		vspan = style[0];
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
	case "CE_change":
		return send(nthChild(nthWord(arg[1], 1)), arg[0],
				nthWord(arg[1], 2, 99), arg[2]);
	break;
	case "CE_lock":
	case "CE_unlock":
		return send(nthChild(nthWord(arg[1], 1)), arg[0], 
				nthWord(arg[1], 2, 99));
	break;
	case "inPreP":
	case "inAnchor":
	case "L": /*???*/
	case "compact":
		return 0;
	break;
	case "setAnchor":
		makeAnchor = arg[1];
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
			tagID = arg[2];
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
				if (offset > 0) return offset + get("y");
			}
		}
		return 0;
	break;
	case "listDepth":
		return 0;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "outputSGML":
		print("<BODY>\n");
		n = countChildren();
		if (n) {
			for (i = 0; i < n; i++)
				send(nthChild(i), "outputSGML");
		}
		print("</BODY>\n");
		return;
	break;
	case "setStyles":
		useTagInfo_align = 1;
		tagPtr = STG_tagPtr("BODY");
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
				/* Only set BDColor from FGColor if not already set by STG */
				if (get("BDColor") == 0) {
					set("BDColor", get("FGColor"));
				}
			}
		}
		return;
	break;
	case "init":
		usual();
		color = getResource("Viola.background_doc");
		if (color) set("BGColor", color);
		color = getResource("Viola.foreground_doc");
		if (color) set("FGColor", color);
		color = getResource("Viola.borderColor_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
	usual();
