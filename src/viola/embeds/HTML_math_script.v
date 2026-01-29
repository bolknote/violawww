
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
		/* Add any pending label text first, parsing brackets */
		if (isBlank(get("label")) == 0) {
			label_text = get("label");
			label_len = strlen(label_text);
			text_start = 0;
			
			for (char_idx = 0; char_idx < label_len; char_idx++) {
				ch = nthChar(label_text, char_idx);
				
				if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
					/* Flush accumulated text before bracket */
					if (char_idx > text_start) {
						tok[tokCount] = 2; /* MINFO_DATA */
						data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
						tokCount++;
					}
					
					/* Add bracket token */
					if (ch == '(') {
						tok[tokCount] = 15; /* MINFO_LPAREN */
					} else if (ch == ')') {
						tok[tokCount] = 16; /* MINFO_RPAREN */
					} else if (ch == '[') {
						tok[tokCount] = 17; /* MINFO_LBRACK */
					} else if (ch == ']') {
						tok[tokCount] = 18; /* MINFO_RBRACK */
					}
					data[tokCount] = "";
					tokCount++;
					
					text_start = char_idx + 1;
				}
			}
			
			/* Flush remaining text after last bracket */
			if (text_start < label_len) {
				tok[tokCount] = 2; /* MINFO_DATA */
				data[tokCount] = nthChar(label_text, text_start, label_len - 1);
				tokCount++;
			}
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
		/* If token is MINFO_DATA (2), parse brackets in data */
		if (arg[1] == 2) {
			label_text = arg[2];
			label_len = strlen(label_text);
			text_start = 0;
			
			for (char_idx = 0; char_idx < label_len; char_idx++) {
				ch = nthChar(label_text, char_idx);
				
				if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
					/* Flush accumulated text before bracket */
					if (char_idx > text_start) {
						tok[tokCount] = 2; /* MINFO_DATA */
						data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
						tokCount++;
					}
					
					/* Add bracket token */
					if (ch == '(') {
						tok[tokCount] = 15; /* MINFO_LPAREN */
					} else if (ch == ')') {
						tok[tokCount] = 16; /* MINFO_RPAREN */
					} else if (ch == '[') {
						tok[tokCount] = 17; /* MINFO_LBRACK */
					} else if (ch == ']') {
						tok[tokCount] = 18; /* MINFO_RBRACK */
					}
					data[tokCount] = "";
					tokCount++;
					
					text_start = char_idx + 1;
				}
			}
			
			/* Flush remaining text after last bracket */
			if (text_start < label_len) {
				tok[tokCount] = 2; /* MINFO_DATA */
				data[tokCount] = nthChar(label_text, text_start, label_len - 1);
				tokCount++;
			}
		} else {
			/* Non-data token, pass through */
			tok[tokCount] = arg[1];
			data[tokCount] = arg[2];
			tokCount++;
		}
		return;
	break;
	case "data":
		/* arg[1]	data - parse brackets */
		label_text = arg[1];
		label_len = strlen(label_text);
		text_start = 0;
		
		for (char_idx = 0; char_idx < label_len; char_idx++) {
			ch = nthChar(label_text, char_idx);
			
			if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
				/* Flush accumulated text before bracket */
				if (char_idx > text_start) {
					tok[tokCount] = 2; /* MINFO_DATA */
					data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
					tokCount++;
				}
				
				/* Add bracket token */
				if (ch == '(') {
					tok[tokCount] = 15; /* MINFO_LPAREN */
				} else if (ch == ')') {
					tok[tokCount] = 16; /* MINFO_RPAREN */
				} else if (ch == '[') {
					tok[tokCount] = 17; /* MINFO_LBRACK */
				} else if (ch == ']') {
					tok[tokCount] = 18; /* MINFO_RBRACK */
				}
				data[tokCount] = "";
				tokCount++;
				
				text_start = char_idx + 1;
			}
		}
		
		/* Flush remaining text after last bracket */
		if (text_start < label_len) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = nthChar(label_text, text_start, label_len - 1);
			tokCount++;
		}
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
		/* Then flush label to tok buffer, parsing bracket characters */
		if (isBlank(get("label")) == 0) {
			label_text = get("label");
			label_len = strlen(label_text);
			text_start = 0;
			
			for (char_idx = 0; char_idx < label_len; char_idx++) {
				ch = nthChar(label_text, char_idx);
				
				if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
					/* Flush accumulated text before bracket */
					if (char_idx > text_start) {
						tok[tokCount] = 2; /* MINFO_DATA */
						data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
						tokCount++;
					}
					
					/* Add bracket token */
					if (ch == '(') {
						tok[tokCount] = 15; /* MINFO_LPAREN */
					} else if (ch == ')') {
						tok[tokCount] = 16; /* MINFO_RPAREN */
					} else if (ch == '[') {
						tok[tokCount] = 17; /* MINFO_LBRACK */
					} else if (ch == ']') {
						tok[tokCount] = 18; /* MINFO_RBRACK */
					}
					data[tokCount] = "";
					tokCount++;
					
					text_start = char_idx + 1;
				}
			}
			
			/* Flush remaining text after last bracket */
			if (text_start < label_len) {
				tok[tokCount] = 2; /* MINFO_DATA */
				data[tokCount] = nthChar(label_text, text_start, label_len - 1);
				tokCount++;
			}
			
			set("label", "");
		}
		return;
	break;
	case "F":
		/* Transfer data from buffer to label and add to tokens NOW (before children) */
		SGMLBuildDoc_setBuff(-1);
		if (isBlank(get("label")) == 0) {
			label_text = get("label");
			label_len = strlen(label_text);
			text_start = 0;
			
			for (char_idx = 0; char_idx < label_len; char_idx++) {
				ch = nthChar(label_text, char_idx);
				
				if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
					/* Flush accumulated text before bracket */
					if (char_idx > text_start) {
						tok[tokCount] = 2; /* MINFO_DATA */
						data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
						tokCount++;
					}
					
					/* Add bracket token */
					if (ch == '(') {
						tok[tokCount] = 15; /* MINFO_LPAREN */
					} else if (ch == ')') {
						tok[tokCount] = 16; /* MINFO_RPAREN */
					} else if (ch == '[') {
						tok[tokCount] = 17; /* MINFO_LBRACK */
					} else if (ch == ']') {
						tok[tokCount] = 18; /* MINFO_RBRACK */
					}
					data[tokCount] = "";
					tokCount++;
					
					text_start = char_idx + 1;
				}
			}
			
			/* Flush remaining text after last bracket */
			if (text_start < label_len) {
				tok[tokCount] = 2; /* MINFO_DATA */
				data[tokCount] = nthChar(label_text, text_start, label_len - 1);
				tokCount++;
			}
			
			set("label", "");
		}
		return -1;
	break;
	case "D":
		/* Transfer any remaining data after children to label and add to tokens */
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			label_text = get("label");
			label_len = strlen(label_text);
			text_start = 0;
			
			for (char_idx = 0; char_idx < label_len; char_idx++) {
				ch = nthChar(label_text, char_idx);
				
				/* Compare with character literals directly */
				if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
					/* Flush accumulated text before bracket */
					if (char_idx > text_start) {
						tok[tokCount] = 2; /* MINFO_DATA */
						data[tokCount] = nthChar(label_text, text_start, char_idx - 1);
						tokCount++;
					}
					
					/* Add bracket token */
					if (ch == '(') {
						tok[tokCount] = 15; /* MINFO_LPAREN */
					} else if (ch == ')') {
						tok[tokCount] = 16; /* MINFO_RPAREN */
					} else if (ch == '[') {
						tok[tokCount] = 17; /* MINFO_LBRACK */
					} else if (ch == ']') {
						tok[tokCount] = 18; /* MINFO_RBRACK */
					}
					data[tokCount] = "";
					tokCount++;
					
					text_start = char_idx + 1;
				}
			}
			
			/* Flush remaining text after last bracket */
			if (text_start < label_len) {
				tok[tokCount] = 2; /* MINFO_DATA */
				data[tokCount] = nthChar(label_text, text_start, label_len - 1);
				tokCount++;
			}
			
			set("label", "");
		}

		/* Check if element has a style attribute for minor matching */
		styleAttr = 0;
		if (savedStyleAttr) {
			styleAttr = savedStyleAttr;
		}
		
		/* Get tag pointer with or without minor */
		if (styleAttr) {
			tagPtr = STG_tagPtr("MATH", "", styleAttr);
		} else {
			tagPtr = STG_tagPtr("MATH");
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
						border = 1;
					}
				}
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
						border = 1;
					}
				}
			}
		}
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
			/* border can be numeric (thickness) or style name */
			/* For now, if border is set to non-zero, use BORDER_BORDER (6) */
			if (arg[2] && arg[2] != "0") {
				border = 1;
				set("border", 6);
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
	case "setStyleAttr":
		/* Save style attribute value for later use in D */
		savedStyleAttr = arg[1];
		return;
	break;
	case "init":
		usual();
/*		SGMLBuildDoc_setColors();*/
		return;
	break;
	}
	usual();
