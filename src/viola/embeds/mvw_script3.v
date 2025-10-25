
/*for(i=0; i<arg[]; i++) print("MVW arg[",i,"]={", arg[i], "}\n");*/

	/* This is a GUI-less version of www.v, which the Motif frontend
	 * wraps around of.
	 *
	 * Author: 	Pei Y. Wei
	 */

	/* URL port configurtion. 0 == off.
	 */
	URLPort = 0;

	switch (arg[0]) {
	case "shownPositionV":
		/* message from Motif interface shell */
		return send("mvw.doc.view.pane", arg[0], arg[1]);
     	break;
	case "historyList_selectedItem":
		return send("mvwHistory", arg[0], arg[1]);
     	break;
	case "hotlistList_add":
		url = send("mvw", "getCurrentDocURL");
		comment = send("mvw", "getCurrentDocTitle");
		HTTPHotListAdd(url, comment, date());
		return comment;
	break;
	case "hotlistList_goto":
		return send("mvw", "show", HTTPHotListGet(0, arg[1]));
	break;
	case "hotlistList_delete":
		url = send("mvw", "getCurrentDocURL");
		comment = send("mvw", "getCurrentDocTitle");
		return 0;
	break;
	case "hotlistList_edit":
		url = send("mvw", "getCurrentDocURL");
		comment = send("mvw", "getCurrentDocTitle");
		return 0;
     	break;
	case "cloneApp":
		/* arg[1]	cookie -- is a unique token to be passed back
		 */
		new = clone(cookie);
		return sendToInterface("showAppClone", cookie, new);
	break;
	case "clonePage":
	case "saveAs":
		/* arg[1]	cookie
		 */
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "reload":
	case "showSource":
		return send(nthChild(0), arg[0]);
	break;
	case "historyQuery":
		/* arg[1]	cookie
		 */
		return mvwHistory("historyQuery", arg[1]);
	break;
	case "showPageClone_return":
		/* arg[1] must be the cookie */
		return sendToInterface("showPageClone", arg[1], arg[2]);
	break;
	case "show":
	case "post":
		if (arg[] == 2)
			stat = send("mvw.doc.view.pane", arg[0], arg[1]);
		else if (arg[] == 3)
			stat = send("mvw.doc.view.pane", arg[0], arg[1], 
							 arg[2]);
		else	stat = send("mvw.doc.view.pane", arg[0], arg[1], 
							 arg[2], arg[3]);
		if (stat) stat = send("mvw.doc.view.pane", "historyRecord");
		return stat;
	break;
	case "show_URL_in_selectionBuffer":
		return send("mvw.doc.view.pane", "show",
				trimEdge(getSelection()));
	break;
	case "showDoc":
	case "showHistoryDoc":
		if (arg[] == 2) {
			stat = send("mvw.doc.view.pane", "show", arg[1]);
		} else {
			stat = send("mvw.doc.view.pane", "show", arg[1],
					arg[2]);
		}
		send("www.doc.view.pane", "historyRecord");/*XXX*/
		return stat;
	break;
	case "showHistory":
		/* arg[1]	cookie
		 * arg[2]	position in history list
		 */
		return mvwHistory("showByPosition", arg[1], arg[2]);
	break;
	case "addToHistory":
		send("mvwHistory", "add", arg[1], arg[2]);
		return;
	break;
	case "changeFonts":
		send("res.font", arg[1]);
		/* bug: only main viewer is told of the font change */
		send("mvw.doc.view.pane", "configSelf");
		return;
	break;
	case "group":
		mvw.doc.title.icon("group", arg[1]);
		return;
	break;
	case "destroyDoc":
		return mvw.doc.view.pane("destroyDoc");
	break;
	case "search":
		mvw.doc.view.pane("search", arg[1]);
		return;
	break;
	case "showButNoRecord":
		mvw.doc.view.pane("show", arg[1]);
		return;
	break;
	case "get_infoOnViolaWWW":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040327020615/http://www.xcf.berkeley.edu/~wei/viola/vw/about_3.3.html");
		return;
	break;
	case "get_helpOnViolaWWW":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040328124311/http://www.xcf.berkeley.edu/~wei/viola/vw/help_xvw_3.3.html");
		return;
	break;
	case "get_demoForViolaWWW":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040219022839/http://www.xcf.berkeley.edu/~wei/viola/violaCentral.html");
		return;
	break;
	case "get_gnnWIC":
		send("www", "showHistoryDoc", 
		 "http://nearnet.gnn.com/wic/newrescat.toc.html");
		return;
	break;
	case "get_cern":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20001110052300/http://webservices.web.cern.ch/WebServices/");
		return;
	break;
	case "get_moreServers":
		send("www", "showHistoryDoc", 
		 "https://web.archive.org/web/20040111090639/http://www.xcf.berkeley.edu/~wei/viola/metaCenters.html");
		return;
	break;
	case "printDoc":
		/* arg[1]	printCmd
		 */
		return;
	break;
	case "saveDoc":
		/* arg[1]	file path
		 */
		return;
	break;
	case "saveSource":
		return;
	break;
	case "queryDocSecurity":
		/* for interface to get doc level security level */
	break;
	case "setSecurityClearence":
		/* coming from interace */
	break;
	case "querySecurityClearence":
		/* send to interface */
	break;
	case "home":
		cursorShape("busy");
		mvw.doc.view.pane("showHistoryDoc", homeDoc);
		mvw.doc.view.pane("historyRecord");
		cursorShape("idle");
		return;
	break;
	case "prev":
		cursorShape("busy");
		wantIt = mvwHistory("prev");
		if (isBlank(wantIt) == 0) {
			mvw.doc.view.pane("showHistoryDoc", wantIt);
			sendToInterface("prev", cookie);
		}
		cursorShape("idle");
		return;
	break;
	case "next":
		cursorShape("busy");
		wantIt = mvwHistory("next");
		if (isBlank(wantIt) == 0) {
			mvw.doc.view.pane("showHistoryDoc", wantIt);
			sendToInterface("next", cookie);
		}
		cursorShape("idle");
		return;
	break;
	case "back":
		cursorShape("busy");
		wantIt = mvwHistory("back");
		if (isBlank(wantIt) == 0) {
			mvw.doc.view.pane("showHistoryDoc", wantIt);
			sendToInterface("back", cookie);
		}
		cursorShape("idle");
		return;
	break;
	case "busy":
		sendToInterface("busyCursor", cookie);
		return cursorShape(arg[0]);
	break;
	case "idle":
		sendToInterface("idleCursor", cookie);
		return cursorShape(arg[0]);
	break;
	case "quit":
		quit();
	break;
	case "homeDocP":
		return homeDoc;
	break;
	case "getCurrentDocURL":
	case "getCurrentDocTitle":
		send("mvw.doc.view.pane", arg[0]);
		return;
	break;
	case "init":
		usual();

		homeDoc = environVar("WWW_HOME");
		if (isBlank(homeDoc) == 1)
			homeDoc = "http://info.cern.ch/hypertext/WWW/TheProject.html";
		if (nthChar(homeDoc, 0) == '/')
			homeDoc = concat("file:", homeDoc);

		HTTPHotListLoad();

		if (URLPort > 0) {
			print("WARNING: port number ", URLPort,
			" is now being used to accept URL fetch directives.");
			if (send(mvwDocuPort("listen", URLPort))) {
				print("ERROR: Sorry, failed to open port ",
				URLPort, " for listening to URL fetches\n");
			}
		}
		return;
	break;
	case "outputSGML":
		send("mvw.doc.view.pane", "outputSGML");
		return;
	break;
	}
	usual();
