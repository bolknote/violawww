
	switch (arg[0]) {
	case "buttonRelease":
		send("www","back");
	break;
	case "enter":
	case "leave":
		send("www.mesg.tf", "suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return concat("Click to go back. document = ",
				send("wwwHistory", "peek_back"));
	break;
	}
	usual();
