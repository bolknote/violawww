
	switch (arg[0]) {
	case "show":
		cloneID++;
		new = clone(cloneID);
		send(new, "show_clone", arg[1], arg[2]);
		send(new, "visible", 1);
		return;
	break;
	case "showByURL":
		cloneID++;
		new = clone(cloneID);
		send(new, "show_cloneByURL", arg[1]);
		send(new, "visible", 1);
		return;
	break;
	case "show_clone":
		send(nthChild(1), "show", arg[1]);
		send(nthChild(2), "show", arg[2]);
		return;
	break;
	case "show_cloneByURL":
		send(nthChild(1), "show", arg[1]);
		send(nthChild(2), "getAndShow", arg[1]);
		return;
	break;
	case "apply":
	case "saveAs":
		return send(nthChild(2), arg[0]);
	break;
	case "dismiss":
		set("visible", 0);
		return;
	break;
	case "init":
		usual();
		cloneID = 0;
		return;
	break;
	}
	usual();
