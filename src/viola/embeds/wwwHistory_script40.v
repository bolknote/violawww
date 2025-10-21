
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		docAddr = wwwHistory.list.tf("next");
		if (isBlank(docAddr) != 1) www("showButNoRecord", docAddr);
		cursorShape("idle");
	break;
	}
	usual();
