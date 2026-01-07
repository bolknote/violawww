
	switch (arg[0]) {
	case 'i':
		return "";
	break;
	case "AA":
		switch (arg[1]) {
		case "LEVEL":
			/* Set security level - 0 or 1 only */
			if (arg[2] == "0") {
				set("security", 0);
			} else {
				/* Set global securityMode so all new objects are untrusted */
				securityMode(1);
				set("security", 1);
			}
		break;
		}
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
	case "config":
		return;
	break;
	}
	usual();

