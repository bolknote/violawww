
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		set("width", arg[2]);
		config();
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
		val = arg[2];
		set("width", arg[3]);
		set("height", arg[4]);
		config();
		objectListSend("children", "_setVar", val);
		return get("height");
	break;
	case "value":
		return send(nthChild(1), "getVar");
	break;
	case "setVar.v":
		val = arg[1];
		send(nthChild(1), "setVar", val);
		return;
	break;
	case "setVar.s":
		val = arg[1];
		send(nthChild(0), "setVar", val);
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
