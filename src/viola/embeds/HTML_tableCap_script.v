
	switch (arg[0]) {
	case "make":
		cellType = 32; /* TABLE_CELL_TYPE_TCAP == 32 */

		set("parent", arg[1]);
		set("width", arg[3]);
		set("label", arg[2]);
		set("paneConfig", arg[4]);
		set("height", 20);

		return get("height") + 2;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "expose":
		usual();
		if (doneP == 0) {
			render();
			doneP = 1;
		}
		return;
	break;
	case "config":
		usual();
		render();
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		color = getResource("Viola.foreground_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
