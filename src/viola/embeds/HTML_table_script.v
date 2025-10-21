
	switch (arg[0]) {
	case "F":
		return -1;
	break;
	case "D":
/*		tagPtr = STG_tagPtr("TABLE");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (title) {
			new = send("HTML_tableCap", "clone");
			objectListAppend_children(new);
			h = send(new, "make", self(), title,
					get("width") - 2, titleAlign);
			SGMLTableFormater(new, titleAtTopP);
		} else {
			SGMLTableFormater();
		}
		return get("height");
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "TABLE");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		if (title) SGMLTableFormater(new, titleAtTopP);
		else SGMLTableFormater();
		vspan += set("height", get("height")) + style[1];
		return vspan;
	break;
	case 'b':
		return border;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "TABLE");
		vspan = style[0];

		if (title) SGMLTableFormater(new, titleAtTopP);
		else SGMLTableFormater();

		set("height", vspan + get("height") + style[1]);
		return get("height");
	break;
	case "inPreP":
		return 0;
	break;
	case "reportTitle":
		title = arg[1];
		titleAtTopP = arg[2];
		titleAlign = arg[3];
		return;
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
		case "BORDER":
			border = 1;
			set("border", 6);
		break;
		case "COMPACT":
			compact = 1; 	/* NOT USED YET */
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
	case "findForm":
	case "findTop":
		return send(parent(), arg[0]);
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		color = getResource("Viola.foreground_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
	usual();
