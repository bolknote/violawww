
	switch (arg[0]) {
	case "keyPress":
		c = key();
		if (c == '\r' || c == '\n') {
			send(parent(), "_ok");
			return;
		} else {
			insert(c);
			return;
		}
	break;
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "contentP":
		return get("content");
	break;
	}
	usual();
