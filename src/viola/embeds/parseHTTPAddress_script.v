
	switch (arg[0]) {
	case "name":
		dd = arg[1];
		doP = 1;
		nameEnd = findPattern(dd, ".html");/*XXX*/
		if (nameEnd == -1) nameEnd = strlen(dd);

		nameBegin = 0;
		for (i = 0; doP ; i++) {
			c = nthChar(dd, i);
			switch (c) {
			case '\0':
				doP = 0;
			break;
			case '.':
				if (findPattern(nthChar(dd, i + 1, 999),
						".") == -1) {
					suffixi = i - 1;
					doP = 0;
				}
			break;
			case '/':
				lastSlash = i;
				nameBegin = i + 1;
			break;
			case '#':
				lastHash = i;
				suffixi = i - 1;
				doP = 0;
			break;
			}
		}
		name = nthChar(dd, nameBegin, suffixi);
		return name;
	break;
	case "anchor":
		dd = arg[1];
		doP = 1;
		anchorBegin = findPattern(dd, "#");
		if (anchorBegin == -1) return "";

		anchorBegin = anchorBegin + 1;
		for (i = anchorBegin; doP ; i++) {
			c = nthChar(dd, i);
			switch (c) {
			case '\0':
				doP = 0;
				suffixi = i - 1;
			break;
			case '.':
				suffixi = i - 1;
				doP = 0;
			break;
			}
		}
		anchor = nthChar(dd, anchorBegin, suffixi);
		return anchor;
	break;
	case "stripIndex":
		anchorBegin = findPattern(arg[1], "?");
		if (anchorBegin == -1) return arg[1];
		return nthChar(arg[1], 1, idx);
	break;
	}
	usual();
