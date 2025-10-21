
	switch (arg[0]) {
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height") + 2;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
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
		set("parent", arg[1]);
		if (isBlank(arg[2]) == 0) set("label", arg[2]);
		w = textWidth(1, get("label")) + 20;
		set("width", w);
		send(parent(), "setWidth", w+2);
		return get("height");
	break;
	case "buttonRelease":
		send(parent(), "acceptForm");
	break;
	case "reset":
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
