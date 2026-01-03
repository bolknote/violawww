
	switch (arg[0]) {
	case "D":
		return 1;
	break;
	case 'i':
		/* Return literal content to parser - it will pass to parent */
		return get("label");
	break;
	case "gotoAnchor":
	case "AI":
		return 0;
	break;
	case "expose":
	case "render":
		return;
	break;
	}
	usual();
