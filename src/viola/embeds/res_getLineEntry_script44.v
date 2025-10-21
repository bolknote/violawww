
	switch (arg[0]) {
	case "buttonRelease":
		send(parent(), "_cancel");
		return;
	break;
	}
	usual();
