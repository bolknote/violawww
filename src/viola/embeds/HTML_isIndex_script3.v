
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("y", arg[1]);
		set("width", arg[2] - 2);
		config();
		return get("height") + 2;
	break;
	case "D":
		send(send(parent(), "findTop"), "isIndex");
		return get("height")+2;
	break;
	case "AA":
		switch (arg[1]) {
		case "LABEL":
			send(nthChild(0), "setLabel", arg[2]);
		break;
		case "VALUE":
			defaultVal = arg[2];
		break;
		}
	break;
	case "clone":
		return clone(arg[1]);
	break;
	case "gotoAnchor":
		return "";
	break;
	case "search":
		send(send(parent(), "findTop"), "search", arg[1]);
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
