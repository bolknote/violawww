
	/* message forwarding service */
	switch (arg[0]) {
	case "show":
	case "post":
		if (arg[] == 2) 
			return send("mvw", arg[0], arg[1]);
		else if (arg[] == 3) 
			return send("mvw", arg[0], arg[1], arg[2]);
		else
			return send("mvw", arg[0], arg[1], arg[2], arg[3]);
	break;
	case "home":
	case "prev":
	case "next":
	case "showDoc":
	case "showHistoryDoc":
	case "destroyDoc":
		return send("mvw", arg[0], arg[1]);
	break;
	case "addToHistory":
		return send("mvwHistory", "add", arg[1], arg[2]);
	break;
	}
	usual();
