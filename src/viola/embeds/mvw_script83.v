
	switch (arg[0]) {
	case "buttonRelease":
		send("mvw", "reload");
	break;
	case "enter":
		send("www.mesg.tf", "suggest", "Click to reload the document");
		return;
	break;
	case "leave":
		send("www.mesg.tf", "clear");
		return;
	break;
	}
	usual();
