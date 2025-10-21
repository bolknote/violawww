
	switch (arg[0]) {
	case "D":
		text = get("label");
		send(parent(), "reportMailHeader", text);
		return -1;
	break;
	case "config":
	case "R":
		return 0;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
