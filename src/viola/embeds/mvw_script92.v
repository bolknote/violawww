
	switch (arg[0]) {
	case "buttonRelease":
		sendToInterface("clone");
	break;
	case "enter":
		send("www.mesg.tf", "suggest", "Click to clone the document");
		return;
	break;
	case "leave":
		send("www.mesg.tf", "clear");
		return;
	break;
	}
	usual();
