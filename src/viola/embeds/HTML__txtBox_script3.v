
	switch (arg[0]) {
	case "make":
		/* arg[1]	parent
		 * arg[2]	txt
		 * arg[3]	width to use
		 */
		set("parent", arg[1]);
		set("width", arg[3]);
		h = send(nthChild(0), "make", arg[2], arg[3]);
		set("height", h);
		return h + 5;
	break;
	case "R": /* resize */
		set("width", arg[1]);
		h = send(nthChild(0), "R", arg[1]);
		set("height", h);
		return h + 5;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		color = getResource("Viola.borderColor_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
	usual();
