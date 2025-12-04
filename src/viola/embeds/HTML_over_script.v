
	switch (arg[0]) {
	case "D":
		print("[OVER D] parent=", parent(), "\n");
		set("y", -10);
		send(parent(), "over");
		return 0;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
