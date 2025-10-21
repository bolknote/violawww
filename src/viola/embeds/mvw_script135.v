
	switch (arg[0]) {
	case "shownPositionV":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "config":
		if (lbarVisible == 1) {
			send(nthChild(0), "resetWidthConstraint", arg[3]);
		}
	break;
	case "reload":
	case "showSource":
		return send(nthChild(0), arg[0]);
	break;
	case "saveAs":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "tear":
	case "quit":
		send(get("parent"), arg[0]);
		return;
	break;
	case "clonePage":
		pagePane = get("content");
		return;
	break;
	case "torn":
		objectListSend_children("torn", arg[1], arg[2]);
		pagePane = get("content");
		return;
	break;
	case "whichPageP":
		return send(pagePane, "whichPageP");
	break;
	case "key_up":
	case "key_down":
		return send(nthChild(0), arg[0]);
	break;
	case "addTool":
	case "addTool_sticky":
	case "removeTool":
	case "destroyTool":
		return send(parent(), arg[0], arg[1]);
	break;
	case "linkSideBar":
		sideBarURL = arg[1];
		sideBarRatio = arg[2];
		sideBarMaxWidth = arg[3];
		send(self(), "lbarConfig", "on", 
			sideBarURL, sideBarRatio, sideBarMaxWidth);
		return;
	break;
	case "lbarConfig":
		switch (arg[1]) {
		case "on":
			set("children", 
			"mvw.doc.view.lbar mvw.doc.view.pane");
			send(nthChild(0), "enable", 
				arg[2], arg[3], arg[4], width());

			send(self(), "configSelf");
			if (lbarVisible == 0) send(nthChild(0), "visible", 1);
			pagePane = nthChild(1);
			lbarVisible = 1;
		break;
		case "off":
			if (lbarVisible == 1) send(nthChild(0), "disable");
			set("children",
			"mvw.doc.view.pane");
			lbarVisible = 0;
			send(self(), "configSelf");
			pagePane = nthChild(0);
		break;
		}
		set("content", pagePane);
		return;
	break;
	case "sliderConfig":
		send(self(), "configSelf");
		pagePane = nthChild(0);
		set("content", pagePane);
		return;
	break;
	case "init":
		usual();
		pagePane = nthChild(0); /* default scrolbar at right side */
		set("content", pagePane);
		return;
	break;
	}
	usual();
