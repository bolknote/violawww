
	switch (arg[0]) {
	case "D":
		cellType = 4; /* TABLE_CELL_TYPE_TB == 4 */
		set("y", -10);	/* out of the way!!! */
		return 1;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
