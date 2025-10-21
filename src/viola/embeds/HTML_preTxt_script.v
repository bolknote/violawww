
	switch (arg[0]) {
	case "expose":
		expose(arg[1], arg[2], arg[3], arg[4]);
		return;
	break;
	case "D": /* done */
		if (isBlank(get("label"))) return 0;
		if (deco) {
			box = send(deco, "clone");
			objectListAppend_children(box);
			h = send(box, "make", self(), 
				get("label"), get("width"));
			return h + 2;
			/* +2 for hot-link-indicator border around IMGs */
		} else {
			inPreP = send(parent(), "inPreP");
			if (inPreP) set("format", 0);
			set("content", get("label"));
			set("label", "");
			isHTML = 1;
			return building_vspan()+2;
			/* +2 for hot-link-indicator border around IMGs */
		}
	break;
	case "F": /* flush */
		return 1;
	break;
	case 'R': /* resize */
		if (style == 0) style = SGMLGetStyle("HTML", "P");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		w = arg[2] - get("x") - style[3];
		set("width", w);
		if (deco) {
			h = send(nthChild(0), "R", w);
			set("height", h);
			return h + style[1];
		} else {
			set("content", trimEdgeQ(get("content")));
			clearWindow();
			vspan += set("height", building_vspan()+2) + style[1];
			/* +2 for hot-link-indicator border around IMGs */
			render();
			return vspan;
		}
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "P");
		vspan = style[0];
		set("width", get("width") - style[3]);
		set("content", trimEdgeQ(get("content")));
		clearWindow();
		render();
		vspan += set("height", building_vspan()) + style[1];
		return vspan;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagIDs[tagIDCount] = arg[2];
			tagIDCount = tagIDCount + 1;
		break;
		case "STYLE":
			switch (arg[2]) {
			case "QUOTE":
			break;
			case "MARGIN":
			break;
			case "NOTE":
				deco = "HTML__txtBox_note";
			break;
			case "CAUTION":
				deco = "HTML__txtBox_caution";
			break;
			case "WARNING":
				set("BDColor", "darkOrange");
				deco = "HTML__txtBox_caution";
			break;
			case "ERROR":
				set("BDColor", "red");
				deco = "HTML__txtBox_error";
			break;
			case "TIMED": /*just for fun*/
				deco = "HTML__txtBox_time";
			break;
			case "NORMAL":
			default:
			break;
			}
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
	case "setAnchor":
		tagIDs[tagIDCount] = arg[1];
		tagIDCount++;
		return;
	break;
	case "gotoAnchor":
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return get("y");
		return 0;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "config":
		/* necessary in case of HPANE triggered resizes */
		clearWindow();
		usual();		
		return;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "outputSGML":
		print("<P>", get("content"), "\n");
/*
		n = anchor....
		if (n) {
			for (i = 0; i < n; i++)
				send(nthChild(i), "outputSGML");
		}
*/
		print("</P>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	case "make":
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		return code_HTML_txt(arg);
	break;
	}
	return code_HTML_txt(arg);
