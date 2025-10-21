
	switch (arg[0]) {
	case "showYaSelf":
		set("visible", 1);
		return;
	break;
	case "getLost":
		set("visible", 0);
		return;
	break;
	}
	usual();
