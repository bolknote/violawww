
	switch (arg[0]) {
	case "buttonRelease":
		send("www", "tear");
	break;
	case "enter":
	case "leave":
		send("www.mesg.tf", "suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click to reload the document";
	break;
	}
	usual();
