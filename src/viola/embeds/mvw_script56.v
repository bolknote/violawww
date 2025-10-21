
	switch (arg[0]) {
	case "buttonRelease":
		send("mvw", "back");
	break;
	case "enter":
		send("www.mesg.tf", "suggest", 
			"Click to go roll back the history list (destructive back up).");
		return;
	break;
	case "leave":
		send("www.mesg.tf", "clear");
		return;
	break;
	}
	usual();
