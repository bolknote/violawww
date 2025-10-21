
	switch (arg[0]) {
	case "buttonRelease":
		send(parent(), "relay1", "clear");
	break;
	}
	usual();
