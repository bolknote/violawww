
/*
print("HTML_input: self=", self(), "\n");
for(i=0;i<arg[];i++) print("arg[",i,"]={",arg[i],"}\n");
*/
	switch (arg[0]) {
	case 'i':
		new = send(self(), "clone");
		if (defaultRows == 0) defaultRows = 1;
		if (inputObj == 0) inputObj = "HTML_input_str";
		if (objWidth == 0) objWidth = 300;
		/* inlined objects don't instantiate clones and have
		 * the clone inserted in the holding object's children list
		 * as usual objects do. So, need to tell parent to adopt
		 * the clone that is created here ... don't work. b/c not
		 * all parents are created then...
		 */
		send(new, "make", inputObj, tagID, defaultVal, 
			defaultRows, objWidth, objHeight, isRadio, 
			checked, disabled, checkWidth, src);
		t = concat("\\o(", new, ")");

		/* reset defaults */
		tagID = "";
		inputObj = "HTML_input_str";
		defaultVal = "";
		defaultRows = 1;
		objWidth = 0;
		objHeight = 22;
		isRadio = 0;
		checked = 0;
		disabled = 0;
		checkWidth = 0;
		src = 0;
		return t;
	break;
	case "make":
		inputObj = arg[1];
		tagID = arg[2];
		defaultVal = arg[3];
		defaultRows = arg[4];
		set("width", arg[5]);
		set("height", arg[6]);
		isRadio = arg[7];
		checked = arg[8];
		disabled = arg[9];
		checkWidth = arg[10];
		src = arg[11];
/*
		tagPtr = STG_tagPtr("INPUT");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (defaultVal == 0) defaultVal = "";/* could be a bad idea*/

		if (checked) defaultVal = 1;

		if (inputObj == -1) return 0; /* ignore */
		if (inputObj == 0) inputObj = "HTML_input_str";

		/* width should really be fed back from the input widgets
		 */
		if (checkWidth) {
			set("width", textWidth(1, defaultVal) + 10);
		}

		new = send(inputObj, "clone");
		objectListAppend_children(new);
		h = send(new, "make", self(), defaultVal,
			get("width") - 2, defaultRows * 22,
			checked, disabled);
		if (h == 0) return 1;
		set("height", h);

		if (inputObj == "HTML_input_image")
			set("width", send(new, "width?") + 2);

		if (form == 0) form = send(parent(), "findForm");
		if (form == 0) {
			print("HTML_input: can't find form. self=",
				self(), "\n");
		} else {
			if (inputObj != "HTML_input_submit" &&
			    inputObj != "HTML_input_reset")
				send(form, "regInputer", self());
		}
		if (isRadio) {
			send(form, "radioReg", tagID, self());
		}
		if (checked) {
			send(nthChild(0), "buttonPress");
			send(nthChild(0), "buttonRelease");
		}
		return h;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		if (style_p == 0) style_p = SGMLGetStyle("HTML", "INPUT");
		vspan = style_p[0];
		set("y", arg[1] + vspan);
		ww = arg[2] - get("x") - style_p[3];
		set("width", ww);
		h = send(nthChild(0), "R", arg[1], ww - 2);
		return vspan + set("height", h) + style_p[1];
	break;
	case "r":
		set("width", get("width") - 10);
		h = send(nthChild(0), "R", 0, get("width"));
		set("height", h);
		return h;
	break;
	case "AI":
		switch (arg[1]) {
		case "TYPE":
			inputObj = "HTML_input_str";
		break;
		case "VALUE":
			defaultVal = "";
		break;
		case "SIZE":
			defaultRows = 1;
			set("height", 29);
		break;
		}
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "TYPE":
			inputType = arg[1];
			switch (arg[2]) {
			case "int":
			case "float":
				inputObj = "HTML_input_int";
				defWidth = 50;
			break;
			case "percent":
				inputObj = "HTML_input_percent";
				defWidth = 300;
			break;
			case "boolean":
			case "check":
			case "checkbox":
				inputObj = "HTML_input_check";
				defWidth = 18;
			break;
			case "radio":
				inputObj = "HTML_input_radio";
				isRadio = 1;
				defWidth = 18;
			break;
			case "doodle":
			case "scribble":
				inputObj = "HTML_input_doodle";
				isRadio = 1;
				defWidth = 300;
			break;
			case "text":/* multiline*/
				inputObj = "HTML_input_text";
				defWidth = 300;
			break;
			case "image":
				inputObj = "HTML_input_image";
			break;
			case "hidden":
				inputObj = "HTML_input_hidden";
				defWidth = 0;
			break;
			case "submit":
				inputObj = "HTML_input_submit";
				defaultRows = 2;
				defWidth = 100;
			break;
			case "reset":
				inputObj = "HTML_input_reset";
				defaultRows = 2;
				defWidth = 100;
			break;
			case "str":
			case "date":
				inputObj = "HTML_input_str";
				defWidth = 300;
			break;
			case "password":
				inputObj = "HTML_input_password";
				defWidth = 300;
			break;
			case "audio":
			default:
				inputObj = "HTML_input_fail";
				defWidth = 300;
			break;
			}
			if (objWidth == 0) objWidth = defWidth;
		break;
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "VALUE":
			defaultVal = arg[2];
		break;
		case "DISABLED":
			disabled = 1;
		break;
		case "ENVVAR":
			defaultVal = environVar(arg[2]);
		break;
		case "SRC":
			src = arg[2];
		break;
		case "SIZE":
			i = findPattern(arg[2], ',');
			if (i == -1) {
				size_cols = int(arg[2]);
				/* extra size to allow for scrollbar */
				objWidth = size_cols * textWidth(0, "n") + 20;
			} else {
				size_cols = int(nthChar(arg[2], 0, i-1));
				defaultRows = int(nthChar(arg[2], i + 1, 99));
				objWidth = size_cols * textWidth(0, 'n');
				objHeight = defaultRows * 22;
			}
		break;
		case "CHECKED":
			checked = 1;
		break;
		case "MINCHARS":
			minChars = arg[2];
		break;
		case "MAXCHARS":
			maxChars = arg[2];
		break;
		case "CHARS":
			maxChars = minChars = arg[2];
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
	case "value":
		/* push this down another level */
		if (inputObj == "HTML_input_image") {
			return send(nthChild(0), "packValue", tagID);
		} else if (inputObj == "HTML_input_radio") {
			return send(nthChild(0), "packValue", tagID);
		} else if (inputObj == "HTML_input_check") {
			return send(nthChild(0), "packValue", tagID);
		} else {
			return concat(HTTPEncodeURL(tagID), '=',
				HTTPEncodeURL(send(nthChild(0), "value")));
		}
	break;
	case "reset":
		return send(nthChild(0), "reset");
	break;
	case "radioOnReq":
		/* tell form that this radio button wants to be ON */
		return send(form, "radioOnReq", tagID, self());
	break;
	case "radioOff":
		/* form calls back to tell this radio button to be OFF*/
		send(nthChild(0), "toggleTo", 0);
		return;
	break;
	case "radioOn":
		/* form calls back to say that this radio button can be ON */
		send(nthChild(0), "toggleTo", 1);
		return;
	break;
	case "acceptForm":
	case "resetForm":
		return send(form, arg[0]);
	break;
	case "minChars?":
		return minChars;
	break;
	case "maxChars?":
		return maxChars;
	break;
	case "setWidth":
		/* kludge. this is called by child obj, to ask for 
		 * width readjustment */
		set("width", arg[1]);
		return;
	break;
	case "src?":
		print("input self=", self(), "\n");
		print("input src=", src, "\n");
		return src;
	break;
	case "regInputer":
		return send(form, arg[0], arg[1]);
	break;
	case "outputSGML":
		print("<INPUT");
		if (tagID) print(" NAME=\"", tagID, "\"");
		if (type) print(" TYPE=\"", inputType, "\"");
		if (checked) print(" CHECKED");
		if (get("maxWidth") < 9999) 
			print(" MAXWIDTH=", get("maxWidth"));
		if (get("minWidth") < 9999) 
			print(" MINWIDTH=", get("minWidth"));
		print(">\n");
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
