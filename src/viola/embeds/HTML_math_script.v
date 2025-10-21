
print("HTML_math: self=", self(), "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
for(i=0;i<arg[];i++) print("arg[",i,"]={",arg[i],"}\n");

	switch (arg[0]) {
	case "config":
print("CAUGHT CONFIG\n");
		return;
	break;
	case "expose":
		test4();
		return;
	break;
	case "flush":
		if (isBlank(get("label"))) return -1;
		tok[tokCount] = 2;
		data[tokCount] = get("label");
		tokCount++;

		return -1;
	break;
	case "entity":
print("ENTITY FLUSH MATH label>>>>>", get("label"), "<<<\n");

		if (isBlank(get("label"))) return 0;
		tok[tokCount] = 2;
		data[tokCount] = get("label");
		tokCount++;

		entity_number = arg[1];
		if (entity_number == 50) {/*infin*/
		} else if (entity_number == 51) { /*integral*/
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 65) { /*sigma*/
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
	case "F":
		SGMLBuildDoc_setBuff(-1);
		if (isBlank(get("label"))) return -1;
/*print("F MATH label>>>>>", get("label"), "<<<\n");
*/
		tok[tokCount] = 2;
		data[tokCount] = get("label");
		tokCount++;

		return -1;
	break;
	case "D":
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2;
			data[tokCount] = get("label");
			tokCount++;
		}

		for (i = 0; i < tokCount; i++) {
			print("math_tok ", i, ":   type=", tok[i], 
				"data={", data[i], "}\n");
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
print("MATH: D after1 width=", width(),"\n");
print("MATH: D after1 height=", height(),"\n");
		set("width", get("width"));
		set("height", get("height"));
print("MATH: D after2 width=", width(),"\n");
print("MATH: D after2 height=", height(),"\n");
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
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

print("MATH: R before  width=", width(),"\n");
print("MATH: R before  height=", height(),"\n");
		SGMLMathFormater(tok, data, tokCount);

		vspan += set("height", get("height")) + style[1];
print("MATH: R after  width=", width(),"\n");
print("MATH: R after  height=", height(),"\n");
print("MATH: R result vspan=", vspan,"\n");
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
