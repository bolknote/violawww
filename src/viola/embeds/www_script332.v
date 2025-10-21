
	switch (arg[0]) {
	case "buttonRelease":
		xx = get("label");
		set("label", get("content"));
		set("content", xx);
		render();
		www.mesg.tf("toggleSuggest");
		return;
	break;
	case "enter":
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click to toggle active helper.";
	break;
	}
	usual();
