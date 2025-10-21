
	switch (arg[0]) {
	case 'i':
		if (send(get("parent"), "inPreP")) tt = get("label");
		else tt = compressSpaces(get("label"));
		return tt;
		/*("\\u(", tt, ")") underline no longer supported in tfed*/
	break;
	case "D":
		return -1;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
