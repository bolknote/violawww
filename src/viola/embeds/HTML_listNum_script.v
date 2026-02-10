
	switch (arg[0]) {
	case "make":
		/* arg[1]	parent
		 * arg[2]	label
		 */
		return send(clone(cloneID()), "parent", arg[1]);
	break;
	case "parent":
		set("parent", arg[1]);
		return self();
	break;
	case "label":
		set("label", arg[1]);
		w = textWidth(1, arg[1]) + 4;
		if (w > get("width")) set("width", w);
		return;
	break;
	case "noBullet":
		set("label", "");
		clearWindow();
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
