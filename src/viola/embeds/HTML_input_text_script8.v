
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height") + 2;
	break;
	case "enter":
		if (disabled) return;
	break;
	case "keyPress":
		if (disabled) {
			bell();
			send("www.mesg.tf", "suggest", 
				"This field has been disabled\n");
			return;
		}
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	disabled
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
		defaultVal = arg[1];
		set("content", defaultVal);
		if (arg[2]) disabled = 1;

		return;
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
	}
	usual();
