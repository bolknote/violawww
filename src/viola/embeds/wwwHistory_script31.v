
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		docAddr = wwwHistory.list.tf("back");
		if (isBlank(docAddr) != 1) www("showButNoRecord", docAddr);
		cursorShape("idle");
	break;
	}
	usual();
