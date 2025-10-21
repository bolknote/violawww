
	switch (arg[0]) {
	case "keyPress":
		if (key() == '\r') {
			send(parent(), "search", currentLine());
			return;
		}
	break;
	case "enter":
		www.mesg.tf("show", "An indexing keyword entry field.");
	break;
	case "leave":
		www.mesg.tf("clear");
	break;
	}
	usual();
