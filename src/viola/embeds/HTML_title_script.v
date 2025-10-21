
	switch (arg[0]) {
	case "D":
		text = get("label");
		send(send(parent(), "findTop"), "reportTitle", text);
		return -1;
	break;
	case 'R':
		return 1;
	break;
	case "config":
		return;
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
