
	switch (arg[0]) {
	case "D":
		return 0;
	break;
	case 'i':
		print("WARNING: INTERPRETING SCRIPT >>", get("label"), "<<\n");
		ss = interpret(get("label"));
		print("INTERPRETION RESULT >>", ss, "<<\n");
		return ss;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
		return;
	break;
	}
	usual();
