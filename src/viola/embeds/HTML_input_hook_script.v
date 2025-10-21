
	switch (arg[0]) {
	case 'i':
		if (tagID) {
			send(parent(), "setAnchor", tagID);
			tagID = 0;
		}
		if (url) {
			t = concat("\\b(", compressSpaces(get("label")),
					"\\b)\\e(", HTTPEncodeURL(url), ") ");
			url = 0;
			return t;
		} else {
			return compressSpaces(get("label"));
		}
	break;
	case "AA":
		switch (arg[1]) {
		case "NAME":
			tagID = arg[2];
		break;
		case "HREF":
			url = arg[2];
		break;
		}
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
