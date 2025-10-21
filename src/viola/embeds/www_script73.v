
	switch (arg[0]) {
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
		objectListSend_children("torn", arg[1]);
		return;
	break;
	case "init":
		tearPageID = 0;
	break;
	case "addTool":
	case "removeTool":
	case "destroyTool":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "whichPageP":
		return send(nthChild(2), "whichPageP");
	break;
	case "outliner":
		if (arg[1]) {
			set("children", 
				"www.doc.title www.doc.view www.doc.ol");
			send(self(), "configSelf");
			olP = 1;
		} else {
			set("children", 
				"www.doc.title www.doc.view");
			send(self(), "configSelf");
			olP = 0;
		}
		return;
	break;
	case "quit":
		set("visible", 0);
		freeSelf();
		return;
	break;
	}
	usual();
