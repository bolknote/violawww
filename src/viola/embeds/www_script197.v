
/*
print("DOC>VIEW: ");
for (i=0; i < arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("\n");
*/
	switch (arg[0]) {
	case "config":
		if (lbarVisible == 1) {
			send(nthChild(0), "resetWidthConstraint", arg[3]);
		}
	break;
	case "tear":
	case "quit":
		send(get("parent"), arg[0]);
		return;
	break;
	case "torn":
		send(pagePane, "torn", arg[1]);
		pagePane = get("content");
		return;
	break;
	case "whichPageP":
		return send(pagePane, "whichPageP");
	break;
	case "key_up":
		send("www.doc.view.sb.slider", "scroll", "up");
		return;
	break;
	case "key_down":
		send("www.doc.view.sb.slider", "scroll", "down");
		return;
	break;
	case "keyPress":
		c = key();
		if (c == ' ')
			send("www.doc.view.sb.slider", "scroll", "down");
		return;
	break;
	case "addTool":
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
			"www.doc.view.lbar www.doc.view.pane www.doc.view.sb");
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
			"www.doc.view.pane www.doc.view.sb");
			lbarVisible = 0;
			send(self(), "configSelf");
			pagePane = nthChild(0);
		break;
		}
		set("content", pagePane);
		return;
	break;
	case "sliderConfig":
		switch (arg[1]) {
		case "left":
			set("children", "www.doc.view.sb www.doc.view.pane");
			send(self(), "configSelf");
			send("www.doc.view.sTUb", "getLost");
			pagePane = nthChild(2);
			send("www.doc.view.pane", "configSiderGeom");
		break;
		case "right":
			set("children", "www.doc.view.pane www.doc.view.sb");
			send(self(), "configSelf");
			send("www.doc.view.sTUb", "getLost");
			pagePane = nthChild(1);
			send("www.doc.view.pane", "configSiderGeom");
		break;
		case "none":
			set("children", "www.doc.view.pane www.doc.view.sTUb");
			send("www.doc.view.sTUb", "showYaSelf");
			send(self(), "configSelf");
			pagePane = nthChild(1);
		break;
		}
		set("content", pagePane);
		return;
	break;
	case "init":
		usual();
		/* default scrolbar at right side, lbar off */
		pagePane = nthChild(0); 
		set("content", pagePane);
		return;
	break;
	}
	usual();
