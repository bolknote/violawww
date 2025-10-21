
	switch (arg[0]) {
	case "D":
		send(send(parent(), "findTop"), "reportAuthor", href);
		href = 0;
		return -1;
	break;
	case "AA":
		switch (arg[1]) {
		case "HREF":
			href = arg[2];
		break;
		}
		return;
	break;
	case 'R':
		return 1;
	break;
	case "config":
		return;
	break;
	case "AI":
	case "gotoAnchor":
		return 0;
	break;
	}
	usual();
