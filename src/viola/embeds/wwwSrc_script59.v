
	switch (arg[0]) {
	case "show":
	case "getAndShow":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "contentP":
	case "print":
	case "saveAs":
		return send(nthChild(0), arg[0]);
	break;
	}
	usual();
