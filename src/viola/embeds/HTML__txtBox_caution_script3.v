
	switch (arg[0]) {
	case "set":
		/* Store colors in global variables for later use in make */
		switch (arg[1]) {
		case "FGColor":
			pendingFGColor = arg[2];
		break;
		case "BGColor":
			pendingBGColor = arg[2];
		break;
		case "BDColor":
			pendingBDColor = arg[2];
		break;
		}
		return;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	txt
		 * arg[3]	width to use
		 * arg[4]	FGColor (optional)
		 * arg[5]	BGColor (optional)
		 * arg[6]	BDColor (optional)
		 */
		set("parent", arg[1]);
		set("width", arg[3]-2);
		
		argc = arg[];
		if (argc > 3) {
			pendingFGColor = arg[4];
			pendingBGColor = arg[5];
			pendingBDColor = arg[6];
			print("### txtBox_caution(parent): received colors FG=", pendingFGColor, " BG=", pendingBGColor, " BD=", pendingBDColor, "\n");
			h = send(nthChild(0), "make", arg[2], arg[3], pendingFGColor, pendingBGColor, pendingBDColor) + 3;
		} else {
			h = send(nthChild(0), "make", arg[2], arg[3]) + 3;
		}
		
		set("height", h);
		eventMask("+pointerMotion +leaveWindow");
		return h + 2;
	break;
	case "R": /* resize */
		set("width", arg[1]-2);
		h = send(nthChild(0), "R", arg[1]) + 3;
		set("height", h);
		return h + 2;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
