
	switch (arg[0]) {
	case "F":
		return get("height");
	break;
	case "option":
		/* arg[1]	select value
		 * arg[2]	select label
		 * arg[3]	checked?
		 */
		optVal[optCount] = arg[1];
		optLabel[optCount] = compressSpaces(arg[2]);
		if (arg[3] == 1) checkedItem = optCount + 1;
		optCount++;
		return;
	break;
	case "pick":
		set("label", optLabel[arg[1]]);
		value = optLabel[arg[1]];
		return;
	break;
	case 'i':
		new = send(self(), "clone");
		send(new, "make", tagID, defaultVal, 
			optVal, optLabel, optCount, checkedItem);
		t = concat("\\o(", new, ")");

		tagID = "";
		defaultVal = "";
		optVal = 0;
		optLabel = 0;
		optCount = 0;
		checkedItem = 0;

		return t;
	break;
	case "make":
		tagID = arg[1];
		defaultVal = arg[2];
		optVal = arg[3];
		optLabel = arg[4];
		optCount = arg[5];
		checkedItem = arg[6];

		/* cheexy way to set width */
		maxLength = 0;
		for (i = 0; i < optCount; i++) {
			/* 1== fontID for "normal"*/
			n = textWidth(1, optLabel[i]);
			if (n > maxLength) maxLength = n;
		}
	 	maxLength = maxLength + 33;
		set("width", maxLength);

/*		tagPtr = STG_tagPtr("SELECT");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (form == 0) form = send(parent(), "findForm");
		if (form == 0) {
			print("HTML_select: can't find form. self=",
				self(), "\n");
		} else {
			send(form, "regInputer", self());
		}

		if (checkedItem == 0) checkedItem = 1;

		set("label", optLabel[checkedItem - 1]);
		value = optLabel[checkedItem - 1];

		txt = "";
		for (i = 0; i < optCount; i++) {
			txt = concat(txt, ".{", optLabel[i], 
				"} {send(self(), \"pick\", ", i, ");}\n");
		}
		set("menuConfig", txt);

		return get("height");
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("y", arg[1] + 2);
		set("width", arg[2] - 10);
		return height();
	break;
	case 'r':
		set("width", width() - 10);
/*BUG.. somehow, right before this point, height is set to 1.
		print("HTML_select: r height={", get("height"), "}\n");
*/
		set("height", 20);
		return get("height");
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "VALUE":
			defaultVal = arg[2];
		break;
		case "ENVVAR":
			defaultVal = environVar(arg[2]);
			/* attrlist ordering might make a difference */
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
		return concat(HTTPEncodeURL(tagID), '=', HTTPEncodeURL(value));
	break;
	case "reset":
		set("label", optLabel[checkedItem - 1]);
		value = optLabel[checkedItem - 1];
		clearWindow();
		render();
		return;
	break;
	case "clone":
		return clone(cloneID());
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
	}
	usual();
