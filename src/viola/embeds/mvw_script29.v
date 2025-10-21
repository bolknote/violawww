
	switch (arg[0]) {
	case "addTool":
	case "addTool_sticky":
	case "removeTool":
	case "destroyTool":
		return send(nthChild(2), arg[0], arg[1]);
	break;
	case "clear":
		return send(nthChild(2), arg[0]);
	break;
	}
	usual();
