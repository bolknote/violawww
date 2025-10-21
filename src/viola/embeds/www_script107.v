
	switch (arg[0]) {
	case "addTool":
	case "addTool_sticky":
		new = object(arg[1]);
		for (i = objectListCount_children(); i >= 0; i--)
			if (nthChild(i) == new) return 1;
		objectListAppend("children", new);
		tweak(new, concat("set(\"parent\", \"", self(), "\");"));
		send(new, "visible", 1);
		config();
		return 1;
	break;
	case "removeTool":
		new = object(arg[1]);
		objectListDelete("children", new);
		send(new, "visible", 0);
		config();
		return 1;
	break;
	case "destroyTool":
		new = object(arg[1]);
		objectListDelete("children", new);
		send(new, "visible", 0);
		send(new, "freeSelf");
		config();
		return 1;
	break;
	case "clear":
		set("children", "");
		return;
	break;
	case "go_url":
		return send("www", "show", arg[1]);
	break;
	case "go_home":
		return send("www", "home");
	break;
	case "go_prev":
		return send("www", "prev");
	break;
	case "go_next":
		return send("www", "next");
	break;
	case "go_back":
		return send("www", "back");
	break;
	}
	usual();
