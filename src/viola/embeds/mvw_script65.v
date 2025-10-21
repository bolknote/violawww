
	switch (arg[0]) {
	case "buttonRelease":
		send("mvw", "prev");
	break;
	case "enter":
		send("www.mesg.tf", "suggest",
			"Click to visit the previous document.");
		return;
	break;
	case "leave":
		send("www.mesg.tf", "clear");
		return;
	break;
	}
	usual();
