
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
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "H1");
		vspan = style[0];
		set("width", width() - style[3]);
		set("content", get("content"));
		clearWindow();
		render();/*may be extraneous */
		vspan += set("height", building_vspan()+2) + style[1];
		return vspan;
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
	case "setAnchor":
		tagID = arg[1];
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
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return get("y");
		return 0;
	break;
	case "D": /* done */
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		if (isBlank(get("label"))) return 0;

		send(self(), "setStyles");	/* stylesheet stuff */

		url = send(parent(), "inAnchor");

		inPreP = send(parent(), "inPreP");
		if (inPreP) set("format", 0);
		if (url) {
			t = concat(" \\b(", trimEdgeQ(get("label")),
					"\\b)\\e(", HTTPEncodeURL(url), ") ");
		} else {
			t = trimEdgeQ(get("label"));
		}
		set("content", t);
		set("label", "");
		return building_vspan()+2;
	break;
	case "outputSGML":
		print("<H1");
		if (tagID) print(" NAME=\"", tagID, "\">");
		else print(">");
		print(get("content"), "</H1>\n");
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
	case "setStyles":
		useTagInfo_align = 1;
		tagPtr = STG_tagPtr("H1");
		if (tagPtr) {
		i = STG_attr(tagPtr, "BGColor");
		if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
			i = STG_attr(tagPtr, "border");
			if (i) {
				if (i != "0") set("border", 6);
			}
			
			fontSlant = STG_attr(tagPtr, "fontSlant");
			fontSize = STG_attr(tagPtr, "fontSize");
			fontSpacing = STG_attr(tagPtr, "fontSpacing");
			fontWeight = STG_attr(tagPtr, "fontWeight");
			fontFamily = STG_attr(tagPtr, "fontFamily");
			
			/* If mono spacing requested, use fixed font */
			if (fontSpacing == "mono") {
				set("_font", 0);
			} else {
			/* Get current default font (H1 default is bold_largest=6) */
			currentFont = get("_font");
			if (currentFont == 0) currentFont = 6;
			
			/* Determine current slant and size from font ID */
			/* If current is fixed and slant/size specified, switch to proportional */
			if (currentFont == 0 && (fontSlant != 0 || fontSize != 0)) {
				slant = "bold"; /* H1 default slant */
			} else if (currentFont >= 0 && currentFont <= 3) {
				slant = "normal";
			} else if (currentFont >= 4 && currentFont <= 6) {
				slant = "bold";
			} else if (currentFont >= 7 && currentFont <= 9) {
				slant = "italic";
			} else {
				slant = "bold";
			}
			
			if (currentFont == 2 || currentFont == 5 || currentFont == 8) {
				size = "_large";
			} else if (currentFont == 3 || currentFont == 6 || currentFont == 9) {
				size = "_largest";
			} else {
				size = "";
			}
			
			/* Override with stylesheet values if provided */
			if (fontSlant) {
				switch (fontSlant) {
				case "italic": 	slant = "italic";	break;
				case "bold": 	slant = "bold";		break;
				default:
				case "normal":	slant = "normal";	break;
				}
			}
			
			if (fontSize) {
				switch (fontSize) {
				case "large": 		size = "_large";	break;
				case "largest": 	size = "_largest";	break;
				default:		size = "";		break;
				}
			}
			if (fontWeight == "bold") slant = "bold";
			
			/* Map font name to font ID */
			if (slant == "normal") {
				if (size == "_large") fontID = 2;
				else if (size == "_largest") fontID = 3;
				else fontID = 1;
			} else if (slant == "bold") {
				if (size == "_large") fontID = 5;
				else if (size == "_largest") fontID = 6;
				else fontID = 4;
			} else if (slant == "italic") {
				if (size == "_large") fontID = 8;
				else if (size == "_largest") fontID = 9;
				else fontID = 7;
			} else {
				fontID = 6; /* fallback to H1 default */
			}
			
			/* Apply font family offset */
			if (fontFamily == "serif" || fontFamily == "times") {
				fontID = fontID + 14;
			} else if (fontFamily == "sans-serif" || fontFamily == "helvetica") {
				/* fontID stays in 0-13 (Helvetica range) */
			} else if (fontFamily == "fixed" || fontFamily == "monospace") {
				fontID = 0;
			} else {
				fontID = fontID + getDefaultFontFamily();
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

	case "runAwayFromHome":
		return send(parent(), "deleteChild", self());
	break;
	case "buttonPress":
		if (editMode) {
		  if (mxy[0] < 3 && mxy[1] < 3) {
			print("HTML_txt: GRAB\n");
			if (top == 0) top = send(parent(), "findTop");
			send(top, "wedgeMeIn", self());
			return;
		  } else {
			if (top == 0) top = send(parent(), "findTop");
			plid = send(parent(), "placeID", self(), "");
			send(top, "lock", self(), plid);
			if (lock == 1) {
				/* unlock */
				set("BDColor", get("BGColor"));
				set("cursor", 0);
				lock = 0;
				return;
			} else {
				/* lock */
				set("BDColor", "red");
				set("cursor", 1);
				lock = 1;
			}
		  }
		}
	break;
	case "edit_focus":
		wxy = windowPosition();
		setMouse(wxy[0] + 2, wxy[1] + 2);
		return;
	break;
	case "keyPress":
		if (editMode) {
			c = key();
			if (c == '\r') {
				insert(key());
				set("content", get("content"));
				h = building_vspan();
				print("BUILDING_VSPAN=", h, "\n");
				set("height", h);
				if (top == 0) top = send(parent(), "findTop");
				send(top, "resizeSelf");
				plid = send(parent(), "placeID", self(), "");

				newTxt = get("content");
				set("content", newTxt);

				send(top, "change", self(), plid, newTxt);
			} else if (c == '	') {
				if (shiftKeyP()) {
					send(parent(), "edit_gotoPrev", 
						self());
				} else {
					send(parent(), "edit_gotoNext", 
						self());
				}
				/*
				send(parent(),
					either (shiftKeyP())
						{"edit_gotoPrev"}
						{"edit_gotoNext"},
					self());
				*/
			} else {
				insert(key());
			}
		}
		return;
	break;
	case "CE_change":
		newData = arg[2];
		set("content", newData);
		h = building_vspan();
		print("RE_BUILDING_VSPAN=", h, "\n");
		set("height", h);
		if (top == 0) top = send(parent(), "findTop");
		send(top, "resizeSelf");
		return;
	break;
	case "CE_lock":
		if (lock == 0) {
			set("BDColor", "yellow");
		}
		return;		
	break;
	case "CE_unlock":
		if (lock == 0) {
			set("BDColor", get("BGColor"));
		}
		return;		
	break;
	case "enter":
/*		if (editMode && lock) {
			set("cursor", 1);
		}
*/
		if (editMode) {
			set("cursor", 1);
		}
		return;
	break;
	case "leave":
/*		if (editMode && lock) {*/
		if (editMode) {
			set("cursor", 0);
/*
			set("BDColor", get("BGColor"));
			set("cursor", 0);
			if (lock == 1) {
				if (top == 0) top = send(parent(), "findTop");
				plid = send(parent(), "placeID", self(), "");
				send(top, "unlock", self(), plid);
				lock = 0;
			}
*/
		} else {
			prevHint = 0;
			www.mesg.tf("clear");
		}
		return;
	break;
	case "editMode":
		editMode = arg[1];
		return;
	break;

	}
	return code_HTML_header_large(arg);
