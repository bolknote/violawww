
	switch (arg[0]) {
	case 'i':
		if (send(get("parent"), "inPreP")) tt = get("label");
		else tt = compressSpaces(get("label"));
		return concat("\\f(0)", tt, "\\f(1)");
	break;
	case "D":
		return -1;
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
