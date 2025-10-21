
	switch (arg[0]) {
	case "D":
		config();
		return -1;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	children list
		 * arg[3]	height
		 */
		set("parent", arg[1]);
		set("children", arg[2]);
		set("height", arg[3]);
		return 0;
	break;
	case "clone":
		return clone(arg[1]);
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
