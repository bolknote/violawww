
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		set("width", arg[2]);
		deepObjectListSend("children", "configSelf");
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
		config();
		send(nthChild(1), "setup");
		return get("height");
	break;
	case "value":
		return send(nthChild(1), "getVar");
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "relay1":
		return send(nthChild(1), arg[1]);
	break;
	case "relay2":
		return send(nthChild(1), arg[1], arg[2]);
	break;
	case "init":
		usual();
		color = getResource("Viola.background_doc");
		if (color) set("BGColor", color);
		return;
	break;
	}
	usual();
