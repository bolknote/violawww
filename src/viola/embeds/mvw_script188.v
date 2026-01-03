
	switch (arg[0]) {
	case "shownPositionV":
		sliderPos = arg[1];
		return send(pageObj, arg[0], sliderPos);
	break;
	case "key_up":
		return send(pageObj, "scrollPageDown");
	break;
	case "key_down":
		return send(pageObj, "scrollPageUp");
	break;
	case "procratinate_show":
		if (hasConfiged) {
			stat = send("mvw.doc.view.pane", "show", arg[1]);
			send("mvw.doc.view.pane", "historyRecord");
		} else {
/* wait after the window has opened and configured to the correct size */
			after(1000, self(), "procratinate_show", arg[1]);
		}
		return;
	break;
	case "show":
	case "post":
	case "showDoc":
	case "showHistoryDoc":
		sendToInterface("busyCursor", cookie);
		cursorShape("busy");
		if (arg[0] == "post") {
			doPost = 1;
			postData = arg[3];
		} else { 
			doPost = 0;
			postData = 0;
		}
		if (torn == 1) {
			if (arg[] == 2) 
				stat = send("mvw.doc.view.pane", arg[0], arg[1]);
			else if (arg[] == 3) 
				stat = send("mvw.doc.view.pane", arg[0], arg[1], arg[2]);
			else	stat = send("mvw.doc.view.pane", arg[0], arg[1], arg[2], arg[3]);
			sendToInterface("idleCursor", cookie);
			cursorShape("idle");
			return stat;
		}
		if (nthChar(arg[1], 0) == '#') {
			pageYPos = send(pageObj, "gotoAnchor", 
					nthChar(arg[1], 1, 999));

			pageHeight = send(pageObj, "vspan");
			heightDiff = pageHeight - get("height");
			heightRatio =  float(heightDiff) / -100.0;

			if (heightDiff > 0) {
				sliderSize = float(get("height")) / float(pageHeight) * 100;
				sliderPos = float(pageYPos) / float(heightDiff) * 100;
				if (sliderPos > 100) sliderPos = 100;
			} else {
				sliderSize = 100;
				sliderPos = 0;
			}
			send(pageObj, "shownPositionV", sliderPos);
		} else {
			/* Reset discovery flag for new page load */
			discoveryReset();

			if (arg[] == 2)
			  normURL = send("normalizeURL", "normalizeURL", arg[1]);
			else 
			  normURL = send("normalizeURL", "normalizeURL", arg[1], arg[2]);

			if (hasConfiged == 0) {
				docToRenderAfterConfigure = normURL;
				sendToInterface("idleCursor", cookie);
				cursorShape("idle");
				return 0;
			}
			docName = normURL;
			docURL = normURL;

			if (findPattern(arg[1], "telnet:") != -1) {
				stat = send("mvw.delegationHandler", 
						"doTelnet", normURL);
				sendToInterface("idleCursor", cookie);
				cursorShape("idle");
				return stat;
			} else if (findPattern(arg[1], "mailto:") != -1) {
				stat = send("mvw.delegationHandler", 
						"doMailTo", normURL);
				sendToInterface("idleCursor", cookie);
				cursorShape("idle");
				return stat;
			}

			anchor = parseHTTPAddress("anchor", normURL);

			if (exist(pageObj) == 1) send(pageObj, "undisplay");

			if (exist(docName) == 1) {
				set("children", docName);
				if (anchor != "")  {
					pageYPos = send(docName, 
						"gotoAnchor", anchor) * -1;
					send(docName, "y", pageYPos);
				} else {
					pageYPos = send(docName, "yP");
				}
				if (send(docName, "configSideBar") == 1) {
					send(parent(), "linkSideBar", 
				  sideBarURL, sideBarRatio, sideBarMaxWidth);
				} else {
					send(parent(), "lbarConfig", "off");
				}
				send(docName, "display", width(), height());

				send(docName, "raise");/*necessary?*/
			} else {
				/* a rough guess at the document type */
				handler = wwwFormatDetect("type", docURL);
				docObj = send("wwwHandlerDispatch", 
					"dispatch", handler, doPost, docURL, 
					docName, self(), get("width"), get("height"),
					anchor, 1, postData);

				/* XXX kludgy stylesheet turn off */
				STG_clean(0);

				cursorShape("idle");
				if (docObj == 0) {
					sendToInterface("warningDialog",
						cookie, concat("Failed to access\n", docURL));
					sendToInterface("idleCursor", cookie);
					cursorShape("idle");
					return 0;
				} else if (docObj == 1) {
					/* It's OK.. no doc object generated
					 * but wasn't an error (ie: to be 
					 * rendered by external viewer)
					 */
					cursorShape("idle");
					return 0;
				}

				if (send(docName, "configSideBar") == 1) {
					send(parent(), "linkSideBar", 
				  sideBarURL, sideBarRatio, sideBarMaxWidth);
				} else {
					send(parent(), "lbarConfig", "off");
				}

				if (insertObjCount > 0) {
					for (i = 0; i < insertObjCount; i++)
						send(insertObj[i], "insert");
					insertObjCount = 0;
					send(self(), "R", 
						get("y"),get("width"));
				}
				send(docName, "display", 
					get("width"), get("height"));
				send(docName, "show");
				pageYPos = send(docName, "yP");
			}
			oo = object(docName);
			if (oldDocName != docName) {
				if (pageObj) {
					send(pageObj, "VW_event", "VIEW_OFF");
				}
				pageObj = oo;
				send(pageObj, "VW_event", "VIEW_ON");
			} else {
				pageObj = oo;
			}

			pageHeight = send(pageObj, "vspan");
			send(self(), "configShare");

			/* Notify peer discovery service after document is parsed
			 * (only active if page contains SC attributes) */
			discoverySetPage(normURL);
		}
		if (docObj != 0) {
			title = send(pageObj, "queryTitle");
			if (isBlank(title)) title = pageObj;

			/* Strip web.archive.org prefix for display */
			displayURL = docURL;
			prefix = "https://web.archive.org/web/";
			prefixLen = strlen(prefix);
			urlStart = nthChar(docURL, 0, prefixLen - 1);
			if (urlStart == prefix) {
				/* findPattern returns position of LAST char of pattern */
				/* "/http" ends at position of "p", so "h" is at slashPos - 3 */
				slashPos = findPattern(docURL, "/http");
				if (slashPos > 0) {
					displayURL = nthChar(docURL, slashPos - 3, strlen(docURL) - 1);
				}
			}

			if (arg[0] == "show") {
			  if (isBlank(title))
				sendToInterface("newDocument", cookie, displayURL);
			  else
				sendToInterface("newDocument", cookie, displayURL, title);
			} else { /* arg[0] == "showHistoryDoc" */
			    if (isBlank(title))
			    	sendToInterface("historyDocument", cookie, displayURL);
			    else
			    	sendToInterface("historyDocument", cookie, displayURL, title);
			}
			sendToInterface("sliderConfig", cookie, sliderPos, sliderSize);
		
			indexP = send(pageObj, "queryIsIndex");
			if (indexP == 0) {
				sendToInterface("searchOff", cookie);
			} else {
				/* plain ISINDEX, or ISINDEX ACTION=...*/
				sendToInterface("searchOn", cookie);
			}
			
		}
		sendToInterface("idleCursor", cookie);
		cursorShape("idle");
		return docName;
	break;
	case "toDoInsert":
		insertObj[insertObjCount] = arg[1];
		insertObjCount++;
		return;
	break;
	case "show_request_by_child":
	case "post_request_by_child":
		if (arg[0] == "post_request_by_child") realMesg = "post";
		else realMesg = "show";

		if (torn == 1) destObj = self();
		else destObj = object("mvw");

		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);
		return stat;
	break;
	case "hintOn":
	case "hintOff":
		return;
	break;
	case "setChildren":
		set("children", arg[1]);
		return;
	break;
	case "configShare":
		heightDiff = pageHeight - get("height");
		heightRatio =  float(heightDiff) / -100.0;
		/* not working right... should maintain proportional offset */
		if (heightDiff > 0) {
			sliderSize = float(height()) / float(pageHeight) * 100;
			sliderPos = float(pageYPos) / float(heightDiff) * -100;
		} else {
			sliderSize = 100;
			sliderPos = 0;
		}
		return;
	break;
	case "configSlider":
		/* arg[1]	pageYPos
		 * arg[2]	pageHeight
		 */
		pageYPos = arg[1];
		pageHeight = arg[2];
		if (pageYPos + pageHeight < get("height")) {
			pageYPos = get("height") - pageHeight;
			if (pageYPos > 0) pageYPos = 0;
			send(pageObj, "y", pageYPos);
		}
		send(self(), "configShare");
		sendToInterface("sliderConfig", cookie, sliderPos, sliderSize);
		return;
	break;
	case "config":
		usual();
		if (send(pageObj, "viewP") == 1) {
			/* when switching from a sidebar'ed document to
			 * a non-sidebar document, this object will be
			 * 'configed' (and before the new document gets
			 * configed... so we don't want to bother 
			 * that document (pageObj) until it is ready
			 * (when viewP == 1).
			 */
			/* Clear our window FIRST to prevent black stripes,
			 * since HTML__doc doesn't have its own window.
			 */
			clearWindow();
			render();
			
			/* ask page object to do the calculation */
			send(pageObj, "resize", get("width"), get("height"));
			pageYPos = send(pageObj, "yP");
			pageHeight = send(pageObj, "vspan");
			if (pageYPos + pageHeight < get("height")) {
				pageYPos = get("height") - pageHeight;
				send(pageObj, "y", pageYPos);
			}
			send(self(), "configShare");
		}
		/* this call should not be necessary... what was it for? */
		/*objectListSend("shownDepend", "kludgeRender");*/

		configed = 1;

		/*XXX a bit tweetchy??????? */
		sendToInterface("sliderConfig", cookie, sliderPos, sliderSize);
		if (hasConfiged == 0) {
			hasConfiged = 1;
			if (docToRenderAfterConfigure) {
				stat = send(self(), "show", 
					docToRenderAfterConfigure);
				if (stat) send(self(), "historyRecord");
			}
		}
		return;
	break;
	case "update":
		pageObj = nthChild(0);
		pageHeight = arg[1];
		heightDiff = pageHeight - get("height");
		heightRatio =  float(heightDiff) / -100.0;
		if (heightDiff > 0) h = arg[1];
		else h = get("height");
		return h;
	break;
	case "destroyDoc":
	case "destroyDoc_qualified":
		send(pageObj, "freeSelf");
		pageObj = 0;
		return;
	break;
	case "addTool":
	case "addTool_sticky":
	case "removeTool":
	case "destroyTool":
		return send(parent(), arg[0], arg[1]);
	break;
	case "search":
		return send(pageObj, "search", arg[1]);
	break;
	case "outputSGML":
		return send(pageObj, "outputSGML");
	break;
	case "mailToAuthor":
		contactURL = send(pageObj, "queryAuthor");
		if (contactURL) {
			res.dialogWithButtons("show", 
			 concat("The declared author contact is:\n", 
				contactURL),
			 "Dismiss", "");
		} else {
			res.dialogWithButtons("show", 
			 "Sorry, no author contact declared in the document.",
			 "Dismiss", "");
		}
		return;
	break;
	case "linkSideBar":
		sideBarURL = arg[1];
		sideBarRatio = arg[2];
		sideBarMaxWidth = arg[3];
		return;
	break;
	case "reload":
		/* is a problem if reloading 'URL#anchor' ? */
		sendToInterface("sliderConfig", cookie, 0, sliderSize);
		return send(pageObj, "reload");
	break;
	case "whichPageP":
		return nthChild(0);
	break;
	case "heightP":
		return get("height");
	break;
	case "expose":
		if (todo) {
			homeDoc = mvw("homeDocP");
			mvw("show", homeDoc);
			todo = 0;
		}
		return;
	break;
	case "reportNextID":
	case 'R':
		return;
	break;
	case "historyRecord":
		send(pageObj, "historyRecord");
		return;
	break;
	case "showSource":
		/* return temporary file */
		sendToInterface("showSourceFile", cookie, 
				HTTPGet(docURL), "editable"); 
		return;
	break;
	case "saveAs":
		/* return temporary file */
		sendToInterface("saveAs", cookie, HTTPGet(docURL), arg[1]);
		return;
	break;
	case "getCurrentDocURL":
		return docURL;
	break;
	case "getCurrentDocTitle":
		return title;
	break;
	case "init":
		usual();
		todo = 0;
		return;
	break;
	case "torn":
		cookie = arg[2];
		torn = 1;
		send(nthChild(0), "torn", arg[1]);
		pageObj = nthChild(0);
		/* make self reset variables */
		send(self(), "update", send(pageObj, "vspan"));
		return;
	break;
	}
	usual();
