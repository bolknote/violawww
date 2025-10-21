
	switch (arg[0]) {
	case "mouseMove":
		hint = processMouseMove();
		if (prevHint != hint) {
			if (isBlank(hint)) www.mesg.tf("clear");
			else www.mesg.tf("show", hint);
		}
		prevHint = hint;
		return;
	break;
	case "leave":
		prevHint = 0;
		www.mesg.tf("clear");
		return;
	break;
	case "expose":
		return expose();
	break;
	case "setAnchor":
		tagID = arg[1];
		return;
	break;
	case "inAnchor":
		return 0;
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
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return get("y");
		return 0;
	break;
	case "D": /* done */
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		if (isBlank(get("label"))) return 0;
		send(self(), "setStyles");	/* stylesheet stuff */
		inPreP = send(parent(), "inPreP");
		if (inPreP) set("format", 0);
		set("content", trimEdgeQ(get("label")));
		set("label", "");
		return building_vspan()+2;
	break;
	case "setStyles":
		useTagInfo_align = 1;
		tagPtr = STG_tagPtr("H3");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
			
			fontSlant = STG_attr(tagPtr, "fontSlant");
			fontSize = STG_attr(tagPtr, "fontSize");
			fontSpacing = STG_attr(tagPtr, "fontSpacing");
			
			/* If mono spacing requested, use fixed font */
			if (fontSpacing == "mono") {
				set("_font", 0);
			} else {
			/* Get current font (H3 default is bold=4) */
			currentFont = get("_font");
			if (currentFont == 0) currentFont = 4;
			
			/* Extract slant and size */
			if (currentFont == 0 && (fontSlant != 0 || fontSize != 0)) slant = "bold"; /* H3 default */
			else if (currentFont <= 3) slant = "normal";
			else if (currentFont <= 6) slant = "bold";
			else slant = "italic";
			
			if (currentFont == 2 || currentFont == 5 || currentFont == 8) size = "_large";
			else if (currentFont == 3 || currentFont == 6 || currentFont == 9) size = "_largest";
			else size = "";
			
			/* Override with stylesheet values */
			if (fontSlant) {
				if (fontSlant == "italic") slant = "italic";
				else if (fontSlant == "bold") slant = "bold";
				else slant = "normal";
			}
			if (fontSize) {
				if (fontSize == "large") size = "_large";
				else if (fontSize == "largest") size = "_largest";
				else size = "";
			}
			
			/* Map to font ID */
			if (slant == "normal") {
				if (size == "_large") fontID = 2;
				else if (size == "_largest") fontID = 3;
				else fontID = 1;
			} else if (slant == "bold") {
				if (size == "_large") fontID = 5;
				else if (size == "_largest") fontID = 6;
				else fontID = 4;
			} else {
				if (size == "_large") fontID = 8;
				else if (size == "_largest") fontID = 9;
				else fontID = 7;
			}
			
				set("_font", fontID);
			}
			
			i = STG_attr(tagPtr, "align");
			if (i) {
				useTagInfo_align = 0;
				switch (i) {
				case "center":
					set("paneConfig", "center");
				break;
				case "left":
					set("paneConfig", "westToEast");
				break;
				case "right":
					set("paneConfig", "eastToWest");
				break;
				}
			}
		}
		return;
	break;
	case "outputSGML":
		print("<H3");
		if (tagID) print(" NAME=\"", tagID, "\"");
		print(">", get("content"), "</H3>\n");
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "ALIGN":
			switch (arg[2]) {
			case "center":
				set("paneConfig", "center");
			break;
			case "left":
				set("paneConfig", "westToEast");
			break;
			case "right":
				set("paneConfig", "eastToWest");
			break;
			}
		break;
		}
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
	return code_HTML_header_small(arg);
