
	switch (arg[0]) {
	case "D":
		cellType = 2; /* TABLE_CELL_TYPE_TR == 2 */
		set("y", -10);	/* out of the way!!! */
		return 1;
	break;
	case "R":
	case "r":
		return 1;
	break;
	case "config":
	case "gotoAnchor":
		return 0;
	break;
	}
	usual();
