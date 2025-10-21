
	switch (arg[0]) {
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "contentP":
		return get("content");
	break;
	}
	usual();
