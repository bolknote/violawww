
/* Debug logging removed */

	switch (arg[0]) {
	case "clone":
		return code_HTML_txt(arg);
	break;
	case "make":
		/* Delegate window creation/placement to text widget implementation */
		return code_HTML_txt(arg);
	break;
	case "visible":
		usual();
		return;
	break;
	case "config":
		return;
	break;
	case "expose":
		test4();
		return;
	break;
	case "entity":
		/* Add any pending label text first */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2;
			data[tokCount] = get("label");
			tokCount++;
		}

		/* Then add the entity token */
		entity_number = arg[1];
		if (entity_number == 51) {/*infin*/
			tok[tokCount] = 21; /*MINFO_INFIN*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 52) { /*integral*/
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 65) { /*pi*/
			tok[tokCount] = 22; /*MINFO_PI*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 68) { /*sigma*/
			tok[tokCount] = 20; /*MINFO_SUM*/
			data[tokCount] = "";
			tokCount++;
		}
		return;
	break;
	case "tok&data":
		/* arg[1]	token
		 * arg[2]	data
		 */
		tok[tokCount] = arg[1];
		data[tokCount] = arg[2];
		tokCount++;
		return;
	break;
	case "data":
		/* arg[1]	data
		 */
		tok[tokCount] = 2;
		data[tokCount] = arg[1];
		tokCount++;
		return;
	break;
	case "tok":
		/* arg[1]	token type
		 */
		tok[tokCount] = arg[1];
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "flush":
		/* First, transfer any pending data from global buffer to label */
		SGMLBuildDoc_setBuff(-1);
		/* Then flush label to tok buffer before sub/sup processing */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		return;
	break;
	case "F":
		/* Just transfer data from buffer to label, don't add to tokens yet */
		SGMLBuildDoc_setBuff(-1);
		return -1;
	break;
	case "D":
		SGMLBuildDoc_setBuff(0);
		/* Add label at the BEGINNING of token array if present */
		if (isBlank(get("label")) == 0) {
			/* Shift existing tokens to make room */
			for (i = tokCount; i > 0; i--) {
				tok[i] = tok[i-1];
				data[i] = data[i-1];
			}
			/* Insert label at position 0 */
			tok[0] = 2; /* MINFO_DATA */
			data[0] = get("label");
			tokCount++;
			set("label", "");
		}

/*		tagPtr = STG_tagPtr("MATH");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		SGMLMathFormater(tok, data, tokCount);
		set("width", get("width"));
		set("height", get("height"));
/*		tokCount = 0;
*/
		return get("height");
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "MATH");
		vspan = style[0];
		/* Do NOT reset x here; keep x set by 'make' from TD */
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);

		SGMLMathFormater(tok, data, tokCount);

		vspan += set("height", get("height")) + style[1];
		
		/* Render - this will create window and draw */
		render();
		return vspan;
	break;
	case 'b':
		return border;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "MATH");
		vspan = style[0];

		SGMLMathFormater(tok, data, tokCount);

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
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "init":
		usual();
/*		SGMLBuildDoc_setColors();*/
		return;
	break;
	}
	usual();
