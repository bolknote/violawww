
	switch (arg[0]) {
	case "buttonRelease":
		send(nthSibling(1), "scroll", "down");
	break;
	case "enter":
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click to scroll down one page.";
	break;
	}
	usual();
