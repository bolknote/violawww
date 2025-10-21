
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		set("width", arg[2]);
		return get("height") + 2;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 */
/*
		tagPtr = STG_tagPtr("HPANE");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		set("parent", arg[1]);
		defaultVal = arg[2];
		set("content", defaultVal);
		set("width", arg[3]);
		set("height", arg[4]);
/*
		send(parent(), "regInputer", self());
		maxChars = send(parent(), "maxChars?");
		if (maxChars) checkChars = 1;
		minChars = send(parent(), "minChars?");
		if (minChars) checkChars = 1;
*/
		return get("height");
	break;
	case "keyPress":
		c = key();
		if (c == '\r' || c == '\n') {
			if (checkChars) send(self(), "checkChars");
			return;
		}
	break;
	case "leave":
/*		send(parent(), "setFormVar", get("content"));*/
		if (checkChars) send(self(), "checkChars");
	break;
	case "checkChars":
		length = strlen(get("content"));
		if (minChars > 0) {
			if (length < minChars) {
				send("www.mesg.tf", "suggest", 
concat("Warning, you have entered less digits than suggested\n"));
			}
		}
		if (maxChars > 0) {
			if (length < maxChars) {
				send("www.mesg.tf", "suggest", 
		"Warning, you have entered more digits than suggested\n");
			}
		}
	break;
	case "value":
		return get("content");
	break;
	case "reset":
		set("content", defaultVal);
		clearWindow();
		render();
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
