
	switch (arg[0]) {
	case "show":
		set("content", target());
		if (get("window")) render();
		return;
	break;
	case "keyPress":
		c = key();
		if (c == '\r') {
			if (isBlank(target())) target("res");
			target(currentLine());
			shell.obj.entry("show");
			return;
		} else {
			insert(c);
			return;
		}
	break;
	case "init":
		set("content", target());
	break;
	}
	usual();
