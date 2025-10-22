
/*
print("HTML_txt: self=", self(), "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
for(i=0;i<arg[];i++) print("arg[",i,"]={",arg[i],"}\n");
print("HTML_txt: editMode=", editMode, "\n");
print("HTML_txt: lock=", lock, "\n");
*/
	switch (arg[0]) {
	case "expose":
		return expose();
	break;
	case "mouseMove":
		hint = processMouseMove();
		if (prevHint != hint) {
			if (isBlank(hint)) www.mesg.tf("clear");
			else www.mesg.tf("show", hint);
		}
		prevHint = hint;
		return;
	break;
	case "inPreP":
		return 0;
	break;
	case "fitIn?":
		/* arg[1]	x
		 * arg[2]	y
		 */
		x = arg[1];
		y = arg[2];
	break;
	case "runAwayFromHome":
		return send(parent(), "deleteChild", self());
	break;
	case "buttonPress":
		if (editMode) {
		  mxy = mouseLocal();
		  if (mxy[0] < 10) {
			print("HTML_txt: GRAB\n");
			my = mxy[1];
			if (my < (height() / 2)) side = 0;
			else side = 1;
			if (top == 0) top = send(parent(), "findTop");
			send(top, "wedgeMeIn", self(), side);
			return;
		  } else {
			if (top == 0) top = send(parent(), "findTop");
			plid = send(parent(), "placeID", self(), "");
			send(top, "lock", self(), plid);
			if (lock == 1) {
				/* unlock */
				set("BGColor", bgcolor);
				render();
				set("cursor", 0);
				lock = 0;
				return;
			} else {
				/* lock */
				bgcolor = get("BGColor");
				set("BGColor", "yellow");
				render();
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
			set("BGColor", "red");
			render();
		}
		return;		
	break;
	case "CE_unlock":
		if (lock == 0) {
			set("BGColor", bgcolor);
			render();
		}
		return;		
	break;
	case "enter":
		if (editMode && lock) {
			set("cursor", 1);
		}
		return;
	break;
	case "leave":
		if (editMode && lock) {
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
	case "D": /* done */
		if (doneSetInPreP == 0) {
			inPreP = send(parent(), "inPreP");
			doneSetInPreP = 1;
		}
		SGMLBuildDoc_setBuff(0);/* necessary ...*/

		if (isBlank(get("label"))) {
			/*XXXXX there is something... \o's..
			 *	Question: how to determine height?
			 */
			if (nthChild(0)) return 20;

			/* no text in this para object. But, there might
			 * be an inlined object containing other objects...
			 * Ie: <P><A><H2>Hozer markup</H2></A>
			 */
/*
			vspan = 0;
			if (nthChild(0)) {
print("TXT: has child!:", nthChild(0), "\n");
				n = countChildren();
print("TXT: n=", n, "\n");
				xx = get("width");
				for (i = 0; i < n; i++) {
				  vspan += send(nthChild(i), "R", vspan, xx);
				}
print("TXT: vspan=", vspan, "................................\n");
				set("height", vspan+10);

print("TXT: height=", get("height"), "................................\n");
				return (vspan + 10);
			}
			return 0;
*/
		}

		/* setStyleAttr was already called before D, so savedStyleAttr is ready */
		send(self(), "setStyles", parent());

		if (deco) {
			box = send(deco, "clone");
			objectListAppend_children(box);
			
			/* Get colors to pass to deco */
			savedFGColor = get("FGColor");
			savedBGColor = get("BGColor");
			savedBDColor = get("BDColor");
			
			if (inPreP) 
			  h = send(box, "make", self(), 
				   get("label"), get("width"),
				   savedFGColor, savedBGColor, savedBDColor);
			else 
			  h = send(box, "make", self(), 
				   trimEdgeQ(get("label")), get("width"),
				   savedFGColor, savedBGColor, savedBDColor);
			return h + 2;
			/* +2 for hot-link-indicator border around IMGs */
		} else {
			if (inPreP) {
				set("format", 0);
				set("font", "fixed");
				set("_font", 0);
				set("content", get("label"));
			} else {
				set("content", trimEdgeQ(get("label")));
			}
			set("label", "");
			isHTML = 1;
			return building_vspan()+2;
			/* +2 for hot-link-indicator border around IMGs */
		}
	break;
	case "F": /* flush */
		return 1;
	break;
	case "R": /* resize */
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
			/* check to see if this Para object has children
			 * objects. This can happen, ie, with this markup
			 * <P><A><H2>foo</H2>
			 */
/*			if (nthChild(0)) {
				n = countChildren();
				xx = get("width");
				for (i = 0; i < n; i++)
				  vspan += send(nthChild(i), "R", vspan, xx);
				set("height", vspan+1);
				return vspan+1;
			} 
*/
/*print("HTML_txt R: label={",get("content"), "}\n");*/
				set("content", get("content"));
				clearWindow();
				vspan += set("height", building_vspan()+2)
					 + style[1];
				/* +2 for hot-link-indicator border around IMGs */
				render();
				return vspan;
		}
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "P");
		vspan = style[0];
		set("width", get("width") - style[3]);
		set("content", get("content"));
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
			tagIDCount++;
		break;
		case "STYLE":
			/* STYLE attribute is now handled by setStyleAttr message from CB_HTML_etag */
			/* This case should not be reached anymore */
		break;
		case "OLD_STYLE_COMPAT":
			/* Old hardcoded styles - for backward compatibility if needed */
			switch (arg[2]) {
			case "NOTE":
				deco = "HTML__txtBox_note";
			break;
			case "CAUTION":
				deco = "HTML__txtBox_caution";
			break;
			case "WARNING":
				/* Colors now come from STG */
				deco = "HTML__txtBox_caution";
			break;
			case "ERROR":
				/* Colors now come from STG */
				deco = "HTML__txtBox_error";
			break;
			case "TIMED": /*just for fun*/
				deco = "HTML__txtBox_time";
			break;
			case "QUOTE":
			case "MARGIN":
			case "NORMAL":
			default:
			break;
			}
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
	case "make":
		send(self(), "setStyles", arg[1]);

		tagIDs[tagIDCount] = arg[6];
		tagIDCount++;

		if (useTagInfo_align)
			if (arg[] > 7) set("paneConfig", arg[7]);

		eventMask("+pointerMotion +leaveWindow");
		return code_HTML_txt(arg);
	break;
	case "setStyleAttr":
		/* Save style attribute value for later use in setStyles/D */
		savedStyleAttr = arg[1];
		return;
	break;
	case "setStyles":
		useTagInfo_align = 1;

		/* Check if element has a style attribute for minor matching */
		/* Can be passed as arg[2] or from savedStyleAttr variable */
		argc = arg[];
		if (argc >= 3) {
			styleAttr = arg[2];
		} else {
			styleAttr = savedStyleAttr;
		}
		
		if (findPattern(arg[1], "address") != -1) {
			/*tagPtr = send(arg[1], "styleSheet");*/
			if (styleAttr) {
				tagPtr = STG_tagPtr("P", "ADDRESS", styleAttr);
			} else {
				tagPtr = STG_tagPtr("P", "ADDRESS");
			}
		} else {
			if (styleAttr) {
				tagPtr = STG_tagPtr("P", "", styleAttr);
			} else {
				tagPtr = STG_tagPtr("P");
			}
		}
		
		if (tagPtr) {
			/* Use STG_attrEx if styleAttr is set (supports minors), else use STG_attr */
			if (styleAttr) {
				i = STG_attrEx(tagPtr, "BGColor");
				if (i) set("BGColor", i);
				i = STG_attrEx(tagPtr, "FGColor");
				if (i) set("FGColor", i);
				i = STG_attrEx(tagPtr, "BDColor");
				if (i) set("BDColor", i);
				i = STG_attrEx(tagPtr, "border");
				if (i) {
					/* border can be numeric (thickness) or style name */
					/* For now, if border is set to non-zero, use BORDER_BORDER (6) */
					if (i != "0") {
						set("border", 6);
						/* Set deco based on styleAttr value */
						if (styleAttr == "WARNING") {
							deco = "HTML__txtBox_caution";
						}
					}
				}
				
				fontSlant = STG_attrEx(tagPtr, "fontSlant");
				fontSize = STG_attrEx(tagPtr, "fontSize");
				fontSpacing = STG_attrEx(tagPtr, "fontSpacing");
			} else {
				i = STG_attr(tagPtr, "BGColor");
				if (i) set("BGColor", i);
				i = STG_attr(tagPtr, "FGColor");
				if (i) set("FGColor", i);
				i = STG_attr(tagPtr, "BDColor");
				if (i) set("BDColor", i);
				i = STG_attr(tagPtr, "border");
				if (i) {
					/* border can be numeric (thickness) or style name */
					/* For now, if border is set to non-zero, use BORDER_BORDER (6) */
					if (i != "0") {
						set("border", 6);
						/* No styleAttr in this branch, so no deco */
					}
				}
				
				fontSlant = STG_attr(tagPtr, "fontSlant");
				fontSize = STG_attr(tagPtr, "fontSize");
				fontSpacing = STG_attr(tagPtr, "fontSpacing");
			}
			
			/* If mono spacing requested, use fixed font and ignore slant/size */
			if (fontSpacing == "mono") {
				set("_font", 0);
			} else {
			/* Get current default font, or use normal (ID=1) */
			currentFont = get("_font");
			if (currentFont == 0) currentFont = 1;
			
			/* Determine current slant and size from font ID */
			/* Note: if current is fixed (0) and slant/size specified, switch to proportional */
			if (currentFont == 0 && fontSlant == 0 && fontSize == 0) {
				slant = "fixed"; size = "";
			} else if (currentFont == 0) {
				/* Switch from fixed to proportional if slant/size specified */
				slant = "normal"; size = "";
			} else if (currentFont == 1) {
				slant = "normal"; size = "";
			} else if (currentFont == 2) {
				slant = "normal"; size = "_large";
			} else if (currentFont == 3) {
				slant = "normal"; size = "_largest";
			} else if (currentFont == 4) {
				slant = "bold"; size = "";
			} else if (currentFont == 5) {
				slant = "bold"; size = "_large";
			} else if (currentFont == 6) {
				slant = "bold"; size = "_largest";
			} else if (currentFont == 7) {
				slant = "italic"; size = "";
			} else if (currentFont == 8) {
				slant = "italic"; size = "_large";
			} else if (currentFont == 9) {
				slant = "italic"; size = "_largest";
			} else {
				slant = "normal"; size = "";
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
				fontID = 1; /* fallback */
			}
			
			set("_font", fontID);
			}
			
			/* Use correct function based on whether we have styleAttr */
			if (styleAttr) {
				i = STG_attrEx(tagPtr, "align");
			} else {
				i = STG_attr(tagPtr, "align");
			}
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
			
			if (styleAttr) {
				i = STG_attrEx(tagPtr, "blink");
			} else {
				i = STG_attr(tagPtr, "blink");
			}
			if (i) {
				blinkRate = i;
				fgc = get("FGColor");
				if (styleAttr) {
					bclr0 = STG_attrEx(tagPtr, "blinkColorOn");
					bclr1 = STG_attrEx(tagPtr, "blinkColorOff");
				} else {
					bclr0 = STG_attr(tagPtr, "blinkColorOn");
					bclr1 = STG_attr(tagPtr, "blinkColorOff");
				}
				after(i, self(), "blink");
			}
		}
		return;
	break;
	case "blink":
		if (blinkOn) {
			blinkOn = 0;
			set("FGColor", bclr1);
		} else {
			set("FGColor", bclr0);
			blinkOn = 1;
		}
		render();
		after(blinkRate, self(), "blink");
		return;
	break;
	case "itemN":
		/*??? it happens. Just here to quiet it*/
		return;
	break;
	case "setAnchor":
		tagIDs[tagIDCount] = arg[1];
		tagIDCount++;
/*		for (i = 0; i < tagIDCount; i++)
			print("######", tagIDs[i], "\n");
*/
		return;
	break;
	case "gotoAnchor":
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return get("y");
		return 0;
	break;
	case "editMode":
		editMode = arg[1];
		return;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "config":
		/* let 'R' do the resizing */
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
	}
	return code_HTML_txt(arg);
