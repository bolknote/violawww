
	switch (arg[0]) {
	case "F":
		return -1;
	break;
	case "D":
/*		text = get("label");
		send(send(parent(), "findTop"), "reportNextID", text);
*/
		return -1;
	break;
	case "R":
		return 0;
	break;
	case "config":
	case "AA":
	case "AI":
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
