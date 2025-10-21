
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		docAddr = wwwHistory.list.tf("prev");
		if (isBlank(docAddr) != 1) www("show", docAddr);
		cursorShape("idle");
	break;
	}
	usual();
