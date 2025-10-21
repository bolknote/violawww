
	switch (arg[0]) {
	case "setVar":
	case "shownPositionH":
		set("content", arg[1]);
		render();
		return;
	break;
	case "_setVar":
		set("content", arg[1]);
		return;
	break;
	case "keyPress":
		if (key() == '\r') {
			v = get("content");
			if (v > 100) {
				v = 100;
				set("content", 100);
				render();
			}
			return;
		}
	break;
	}
	usual();
