
	switch (arg[0]) {
	case "D":
		return 0;
	break;
	case 'i':
		return concat("\\f(0)*\\f(1)", compressSpaces(get("label")));
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
