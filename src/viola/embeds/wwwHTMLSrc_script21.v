
	switch (arg[0]) {
	case "show":
		send(nthChild(0), "show", arg[1]);
		return;
	break;
	case "contentP":
		return send(nthChild(0), "contentP");
	break;
	}
	usual();
