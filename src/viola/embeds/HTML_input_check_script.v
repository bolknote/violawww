
	switch (arg[0]) {
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		return get("height");
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
		valDefault = arg[2];
		return get("height");
	break;
	case "buttonPress":
	case "buttonRelease":
		usual();
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "packValue":
		if (get("toggleState")) 
			return concat(HTTPEncodeURL(arg[1]), '=',
				HTTPEncodeURL(valDefault));
		return 0;
	break;
	case "value":
		return get("toggleState");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
