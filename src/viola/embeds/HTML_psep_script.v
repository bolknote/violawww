
	switch (arg[0]) {
	case "D":
		return 0;
	break;
	case 'i':
		send(parent(), "makeTxt");
		return "";
	break;
	}
	usual();
