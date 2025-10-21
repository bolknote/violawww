
	switch (arg[0]) {
	case 'i':
		send(parent(), "body");
		return "";
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
