
	switch (arg[0]) {
	case 'i':
		/*XXX this is so so sincerely cheezy */
		if (send(get("parent"), "inPreP")) tt = get("label");
		else tt = compressSpaces(get("label"));

		pn = str(parent());
		if (findPattern(pn, "pre") != -1) {
			return concat("\\f(4)", tt, "\\f(0)");
		} else if (findPattern(pn, "example") != -1) {
			return concat("\\f(4)", tt, "\\f(0)");
		} else if (findPattern(pn, "header_medium") != -1) {
			return concat("\\f(5)", tt, "\\f(2)");
		} else {
			return concat("\\f(4)", tt, "\\f(1)");
		}
	break;
	case "D":
		return -1;
	break;
	case "inPreP":
		return send(get("parent"), "inPreP");
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
