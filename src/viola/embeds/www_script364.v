
	switch (arg[0]) {
	case "buttonRelease":
		www.url.tf("getURLFromClipBuffer");
	break;
	case "enter":
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click to read and follow URL from X selection buffer.";
	break;
	}
	usual();
