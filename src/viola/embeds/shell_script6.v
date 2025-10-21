
	switch (arg[0]) {
	case "targetSet":
		shell.obj.entry("show");
		return;
	break;
	case "raise":
		raise();
		return;
	break;
	case "dismiss":
		set("visible", 0);
		return;
	break;
	}
	usual();
