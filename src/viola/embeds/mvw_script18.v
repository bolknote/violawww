
	switch (arg[0]) {
	case "show":
		set("content", arg[1]);
		render();
		return;
	break;
	case "torn":
		return;
	break;
	}
	usual();
