
	switch (arg[0]) {
	case "buttonRelease":
		send("www", "prev");
	break;
	case "enter":
	case "leave":
		send("www.mesg.tf", "suggest", get("name"), arg[0]);
		encounter = enconter + 1;
		return;
	break;
	case "hint":
		return concat("Click to visit the previous document = ",
				wwwHistory("peek_prev"));
	break;
	}
	usual();
