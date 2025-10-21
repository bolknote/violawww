
	switch (arg[0]) {
	case "buttonPress":
		copyArea(0,0,width(),height(),1,1);
		return;
	break;
	case "buttonRelease":
		send("www","home");
	break;
	case "enter":
	case "leave":
		send("www.mesg.tf", "suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click the house icon to visit home page.";
	break;
	}
	usual();
