
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height");
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 * arg[5]	checked
		 * arg[6]	disabled
		 */
/*		tagPtr = STG_tagPtr("INPUT");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (arg[6]) disabled = 1;

		set("parent", arg[1]);
		defaultVal = arg[2];
		set("content", defaultVal);
		set("width", arg[3]);
		set("height", arg[4]);
		return get("height");
	break;
	case "enter":
		if (disabled == 1) return;
	break;
	case "keyPress":
		if (disabled == 1) {
			bell();
			send("www.mesg.tf", "suggest", 
				"This field has been disabled\n");
			return;
		} else {
			c = key();
			if (c == '\r' || c == '\n') {
				if (checkChars) send(self(), "checkChars");
				return;
			}
		}
	break;
	case "checkChars":
		length = strlen(get("content"));
		if (minChars > 0) {
			if (length < minChars) {
				send("www.mesg.tf", "suggest", 
	"Warning, you have entered less characters than suggested\n");
			}
		}
		if (maxChars > 0) {
			if (length < maxChars) {
				send("www.mesg.tf", "suggest", 
	"Warning, you have entered more characters than suggested\n");
			}
		}
	break;
	case "leave":
		if (checkChars) send(self(), "checkChars");
	break;
	case "value":
		return trimEdge(get("content"));
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
