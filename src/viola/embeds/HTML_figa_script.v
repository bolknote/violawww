
	switch (arg[0]) {
	case 'i':
		send(parent(), "addFigA", ref,
			int(nthWord(area, 1)), int(nthWord(area, 2)),
			int(nthWord(area, 3)), int(nthWord(area, 4)));
		return -1;
	break;
	case "AA":
		switch (arg[1]) {
		case "AREA":
			area = arg[2];
		break;
		case "HREF":
			ref = arg[2];
		break;
		}
		return;
	break;
	case "AI":
		return 0;
	break;
	}
	usual();
