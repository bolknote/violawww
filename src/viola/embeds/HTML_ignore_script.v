
	switch (arg[0]) {
	case 'i':
		return "";
	break;
	case "AA":
		return;
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
