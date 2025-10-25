
/*
print("www: ");
for (i=0; i < arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("\n");
*/
	/* Application: ViolaWWW
	 * Author: 	Pei Y. Wei
	 *
	 */
	/* URL port configurtion.
	 * 
	URLPort = 8081;
	URLListen = "/usr/work/viola/src/viola/listen";
	 */

	switch (arg[0]) {
	case "show":
	case "post":
		cursorShape("busy");
		if (arg[] == 2)
			stat = send("www.doc.view.pane", arg[0], arg[1]);
		else if (arg[] == 3)
			stat = send("www.doc.view.pane", arg[0], arg[1], 
							 arg[2]);
		else
			stat = send("www.doc.view.pane", arg[0], arg[1], 
							 arg[2], arg[3]);
		cursorShape("idle");
		return stat;
	break;
	case "showDoc":
	case "showHistoryDoc":
		cursorShape("busy");
		if (arg[] == 2)
			stat = send("www.doc.view.pane", "show", arg[1]);
		else if (arg[] == 3)
			stat = send("www.doc.view.pane", "show", arg[1], 
							 arg[2]);
		else
			stat = send("www.doc.view.pane", "show", arg[1], 
							 arg[2], arg[3]);
		send("www.doc.view.pane", "historyRecord");
		cursorShape("idle");
		return stat;
	break;
	case "addToHistory":
		send("wwwHistory", "add", arg[1], arg[2]);
		return;
	break;
	case "group":
/*		send("www.doc.title.icon", "group", arg[1]);*/
		return;
	break;
	case "showSrc":
	case "clonePage":
	case "destroyDoc":
		return send("www.doc.view.pane", arg[0]);
	break;
	case "search":
		return send("www.doc.view.pane", "search", arg[1]);
	break;
	case "olAdd":
/*		olObj[olIdx] = arg[1];*/
		olData[olIdx] = arg[2];
		olIdx++;
		return;
	break;
	case "olReset":
		olIdx = 0;
		return;
	break;
	case "olData":
		tt = "";
		for (i = 0; i < olIdx; i++) tt = concat(tt, olData[i], "\n");
		return tt;
	break;
	case "showButNoRecord":
		send("www.doc.view.pane", "show", arg[1]);
		return;
	break;
	case "CE_change":
		/* arg[1] 	CE objPath
		 * arg[2]	CE newData
		 */
		return send("www.doc.view.pane", arg[0], arg[1], arg[2]);
	break;
	case "CE_lock":
	case "CE_unlock":
		/* arg[1] 	CE objPath
		 */
		return send("www.doc.view.pane", arg[0], arg[1]);
	break;
	case "about":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040327020615/http://www.xcf.berkeley.edu/~wei/viola/vw/about_3.3.html");
		return;
	break;
	case "help":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040328124311/http://www.xcf.berkeley.edu/~wei/viola/vw/help_xvw_3.3.html");
		return;
	break;
	case "demos":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040219022839/http://www.xcf.berkeley.edu/~wei/viola/violaCentral.html");
		return;
	break;
	case "metaCenters":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040111090639/http://www.xcf.berkeley.edu/~wei/viola/metaCenters.html");
		return;
	break;
	case "home":
		send("www", "showHistoryDoc", homeDoc);
		return;
	break;
	case "prev":
		cursorShape("busy");
		wantIt = wwwHistory("prev");
		if (isBlank(wantIt))
			send("www.mesg.tf", "alert", 
				"No ``previous'' document to go to.");
		else send("www.doc.view.pane", "show", wantIt);
		cursorShape("idle");
		return;
	break;
	case "next":
		cursorShape("busy");
		wantIt = send("wwwHistory", "next");
		if (isBlank(wantIt))
			send("www.mesg.tf", "alert", 
				"No ``next'' document to go to.");
		else send("www.doc.view.pane", "show", wantIt);
		cursorShape("idle");
		return;
	break;
	case "back":
		cursorShape("busy");
		wantIt = send("wwwHistory", "back");
		if (isBlank(wantIt))
			send("www.mesg.tf", "alert", 
				    "No Previous document to go back to.");
		else send("www.doc.view.pane", "show", wantIt);
		cursorShape("idle");
		return;
	break;
	case "reload":
		cursorShape("busy");
		send("www.doc.view.pane", arg[0]);
		cursorShape("idle");
		return;
	break;
	case "tear":
		cursorShape("busy");
		send(nthChild(1), "tear");
		cursorShape("idle");
		return;
	break;
	case "authorContact":
		send("www.doc.view.pane", "mailToAuthor");
		return;
	break;
	case "raise":
		raise();
		if (get("window")) windowName("violaWWW");
		return;
	break;
	case "busy":
	case "idle":
		cursorShape(arg[0]);
		return;
	break;
	case "quit":
		quit();
/*
		res("decAppCount");
		demo("visible", 0);
*/
		return;
	break;
	case "openURL":
		winPos = windowPosition();
		x = winPos[0] + 20;
		y = winPos[1] + 170;
		w = width() - 40;
		h = 80;
		send("wwwURL", "open", lastURLOpened, self(), x, y, w, h);
		return;
	break;
	case "gotURLToOpen":
		cursorShape("busy");
		lastURLOpened = arg[1];
		send("www", "show", lastURLOpened);
		send("www.doc.view.pane", "historyRecord");
		cursorShape("idle");
		return;
 	break;
	case "searchByTag":
		send("www.doc.view.pane", "searchByTag", arg[1], arg[2]);
		return;
	break;
	case "homeDocP":
		return homeDoc;
	break;
	case "changeFonts":
		send("res.font", arg[1]);
		/* bug: only main viewer is told of the font change */
		send("www.doc.view.pane", "configSelf");
		return;
	break;
	case "visible":
		if (arg[1] == 1) res("incAppCount");
	break;
	case "init":
		usual();
		t = getResource("Viola.x");
		if (isBlank(t) == 0) set("x", t);
		t = getResource("Viola.y");
		if (isBlank(t) == 0) set("y", t);
		t = getResource("Viola.width");
		if (isBlank(t) == 0) set("width", t);
		t = getResource("Viola.height");
		if (isBlank(t) == 0) set("height", t);
		
		res("incAppCount");

		homeDoc = argument();
		if (isBlank(homeDoc) == 1)
			homeDoc = environVar("WWW_HOME");
		if (isBlank(homeDoc) == 1) 
			homeDoc = "https://web.archive.org/web/20040307145205/http://www.xcf.berkeley.edu/~wei/viola/violaStartUp.html";
		if (nthChar(homeDoc, 0) == '/')
			homeDoc = concat("file:", homeDoc);

		after(10, "www", "show", homeDoc);

		if (URLPort > 0) {
			print("WARNING: port number ", URLPort,
			" is now being used to accept URL fetch directives.");
			if (send("wwwDocuPort", "listen", URLPort, URLListen)){
				print("ERROR: Sorry, failed to open port ",
				URLPort, " for listening to URL fetches\n");
			}
		}
		HTTPHotListLoad();
		lastURLOpened = "";

		/* start up in edit mode */
/*		after(1000, "www", "editMode", 1); */

		return;
	break;
	case "showHotFolder":
		send("wwwHotFolder", "render");
		return;
	break;
	case "addCurrentToHotFolder":
		send("wwwHotFolder", "addCurrent");
		return;
	break;
	case "outputSGML":
		send("www.doc.view.pane", "outputSGML");
		return;
	break;
	case "getCurrentDocURL":
	case "getCurrentDocTitle":
		send("www.doc.view.pane", arg[0]);
		return;
	break;
	case "editMode":
		send("www.doc.view.pane", arg[0], arg[1]);
		return;
	break;
	case "version":
		return "Version 4.0 Beta (2025)";
	break;
	case "winPosition":
		return windowPosition();
	break;
	}
	usual();
