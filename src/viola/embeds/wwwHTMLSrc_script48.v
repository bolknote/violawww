
	switch (arg[0]) {
	case "apply":
	case "store":
	case "dismiss":
		send(get("parent"), arg[0]);
		return;
	break;
	}
	usual();
