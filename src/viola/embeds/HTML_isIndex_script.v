
	switch (arg[0]) {
	case "setLabel":
		set("content", arg[1]);
		set("maxWidth", textWidth(1, argp[1]) + 10);
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
