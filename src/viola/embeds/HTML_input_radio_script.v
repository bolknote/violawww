
	switch (arg[0]) {
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		return get("height");
	break;
	case "make":
		/* arg[1]	tagID
		 * arg[2]	valDefault
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
		set("parent", arg[1]);
		valDefault = arg[2];
		checked = arg[5];
		return get("height");
	break;
	case "buttonRelease":
		send(parent(), "radioOnReq");
		return;
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
	case "reset":
		if (get("toggleState")) {
			if (checked == 0) {
				set("toggleState", 0);
				clearWindow();
				render();
			}
		} else {
			if (checked == 1) {
				set("toggleState", 1);
				clearWindow();
				render();
			}
		}
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		color = getResource("Viola.background_doc");
		if (color) set("BGColor", color);
		color = getResource("Viola.foreground_doc");
		if (color) set("FGColor", color);
		return;
	break;
	}
	usual();
