
	switch (arg[0]) {
	case "shownPositionV":
		return send(nthChild(2), arg[0], arg[1]);
	break;
	case "addTool":
	case "addTool_sticky":
	case "removeTool":
	case "destroyTool":
		return send("mvwTools", arg[0], arg[1]);
	break;
	case "clear":
		return send("mvwTools", arg[0]);
	break;
	case "reload":
	case "showSource":
		return send(nthChild(2), arg[0]);
	break;
	case "saveAs":
		return send(nthChild(2), arg[0], arg[1]);
	break;
	case "clonePage":
		/* arg[1]	cookie
		 */
		send(nthChild(2), "clonePage");
		tearPageID = tearPageID + 1;
		new = clone(tearPageID);
		tweak(new, "set(\"parent\", \"\");");
		send(new, "torn", send(nthChild(2), "whichPageP"), arg[1]);
		send(parent(), "showPageClone_return", arg[1], new);
		return;
	break;
	case "tear":
		tearPageID = tearPageID + 1;
		new = clone(tearPageID);
		tweak(new, "set(\"parent\", \"\");");
		send(new, "torn", send(nthChild(2), "whichPageP"));
		send(new, "render");
		return;
	break;
	case "torn":
		set("label", 
			send(send(nthChild(2), "whichPageP"), "queryAddress"));
		objectListSend_children("torn", arg[1], arg[2]);
		return;
	break;
	case "init":
		usual();
		tearPageID = 0;
		return;
	break;
	case "whichPageP":
		return send(nthChild(2), "whichPageP");
	break;
	case "quit":
		set("visible", 0);
		/*XXX should destroy */
		return;
	break;
	}
	usual();
