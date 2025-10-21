
	switch (arg[0]) {
	case "expose":
		return;
	break;
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
	case "noBullet":
		return freeSelf();
	break;
	case "R":
	case "config":
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		color = getResource("Viola.foreground_doc");
		if (color) set("BGColor", color);
		return;
	break;
	}
	usual();
