
	if (arg[0] == "show") {
		set("content", arg[1]);
		render();
		return;
	}
	usual();
