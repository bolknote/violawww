
	switch (arg[0]) {
	case "buttonPress":
		copyArea(0,0,width(),height(),1,1);
		return;
	break;
	case "buttonRelease":
		www("next");
	break;
	case "enter":
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return concat("Click to visit the next document = ",
				wwwHistory("peek_next"));
	break;
	}
	usual();
