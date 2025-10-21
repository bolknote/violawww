
	switch (arg[0]) {
	case "buttonRelease":
		send("mvw","home");
	break;
	case "enter":
		send("www.mesg.tf", "suggest", 
			"Click the house icon to visit home page.");
		return;
	break;
	case "leave":
		send("www.mesg.tf", "clear");
		return;
	break;
	}
	usual();
