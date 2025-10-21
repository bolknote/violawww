
	switch (arg[0]) {
	case "buttonRelease":
		send(parent(), "dismiss");
		return;
	break;
	}
	usual();
