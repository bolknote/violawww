
	switch (arg[0]) {
	case "keyPress":
		c = key();
		if (c == '\r') send(parent(), "_ok");
		else insert(c);
		return;
	break;
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "contentP":
		return get("content");
	break;
	case "_cut":
		set("content", trimEdge(getSelection()));
		render();
		return;
	break;
	case "_clear":
		set("content", "");
		render();
		return;
	break;
	}
	usual();
