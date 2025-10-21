
	switch (arg[0]) {
	case "make":
		/* arg[1]	defaultValue
		 */
		set("shownPositionH", arg[1]);
		return;
	break;
	case "setVar":
		set("shownPositionH", arg[1]);
		render();
		return;
	break;
	case "_setVar":
		set("shownPositionH", arg[1]);
		return;
	break;
	case "getVar":
		return get("shownPositionH");
	break;
	case "buttonRelease":
		send(parent(), "setVar.s", get("content"));
	break;
	}
	usual();
