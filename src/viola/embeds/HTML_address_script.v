
	switch (arg[0]) {
	case "F":
		h = 0;
/*		SGMLBuildDoc_setBuff(-1);*/
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[2], 
				get("width") - style_p[3] - style_p[2],
				SGMLBuildDoc_span(), makeAnchor, paneConfig);
			makeAnchor = 0;
		} 
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D": /* done */
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[2], 
				get("width") - style_p[3] - style_p[2],
				h, makeAnchor, paneConfig);
			makeAnchor = 0;
		}
		set("height", h);
		return h;
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
		case "ALIGN":
			switch (arg[2]) {
			case "center":
				paneConfig = "center";
			break;
			case "left":
				paneConfig = "westToEast";
			break;
			case "right":
				paneConfig = "eastToWest";
			break;
			}
		break;
		}
		return;
	break;
	case "data":
		SGMLBuildDoc_setBuff(-1);
		return compressSpaces(get("label"));
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "ADDRESS");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1] + 20;
		return vspan;
	break;
	case 'T':
		/* arg[1] = y
		 * arg[2] = width
		 */
		h = get("height");
		parentHeight = send(parent(), "heightP");
		heightDiff = h - parentHeight;
		if (heightDiff > 0) {
			heightRatio =  float(heightDiff) / -100.0;
		} else {
			heightRatio = 0;
			h = parentHeight;
			set("height", h);
		}
		prevWidth = arg[2];
		prevHeight = parentHeight;

		return h;
	break;
	case "inAnchor":
	case "gotoAnchor":
		return 0;
	break;
	case "setAnchor":
		makeAnchor = arg[1];
		return;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "config":
		return;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "styleSheet":
		return tagPtr;
	break;
	case "setStyles":
		if (tagPtr == 0) tagPtr = STG_tagPtr("ADDRESS");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
			i = STG_attr(tagPtr, "fontSlant");
		}
		return;
	break;
	case "outputSGML":
		print("<ADDRESS");
		if (tagID) print(" NAME=\"", tagID, "\">\n");
		else print(">\n");
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i),
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset;
			}
		}
		print("</ADDRESS>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
