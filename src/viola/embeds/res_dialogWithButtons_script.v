
	switch (arg[0]) {
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "buttonRelease":
		res.dialogWithButtons.buttons("cinfo");
		return;
	break;
	}
	usual();
