
	switch (arg[0]) {
	case "show":
	case "dismiss":
		send(get("parent"), arg[0]);
	break;
	}
	usual();
