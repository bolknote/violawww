
	switch (arg[0]) {
	case 'i':
		/*XXX this is so so cheezy-- stop gap solution */
		if (send(get("parent"), "inPreP")) tt = get("label");
		else tt = compressSpaces(get("label"));

		pn = str(parent());
		if (findPattern(pn, "pre") != -1) {
			return concat("\\f(7)", tt, "\\f(0)");
		} else if (findPattern(pn, "example") != -1) {
			return concat("\\f(7)", tt, "\\f(0)");
		} else if (findPattern(pn, "header_big") != -1) {
			return concat("\\f(9)", tt, "\\f(6)");
		} else if (findPattern(pn, "header_medium") != -1) {
			return concat("\\f(8)", tt, "\\f(5)");
		} else if (findPattern(pn, "header_small") != -1) {
			return concat("\\f(7)", tt, "\\f(4)");
		} else {
			return concat("\\f(7)", tt, "\\f(1)");
		}
	break;
	case "D":
		return -1;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "configSelf":
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
