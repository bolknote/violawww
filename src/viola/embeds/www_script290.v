
	switch (arg[0]) {
	case "shownPositionH":
	case "shownPositionV":
		return send(docObj, "shownPositionV", arg[1]);
	break;
	case "barScroll":
		if (arg[1] == "down") {
			pgPosPct += 10;
			if (pgPosPct > 100) pgPosPct = 100;
		} else {
			pgPosPct -= 10;
			if (pgPosPct < 0) pgPosPct = 0;
		}
		return send(docObj, "shownPositionV", pgPosPct);
	break;
	case "show":
		barURL = arg[1];
		barWidth = arg[2];

		set("width", barWidth);

		pgPosPct = 0;

		handler = wwwFormatDetect("type", barURL);
		send("www.mesg.tf", "show", 
			    concat("Getting sidebar from ", barURL));

		docObj = send("wwwHandlerDispatch", 
				"dispatch", handler,
				0, barURL,
				barURL, self(),
				int(barWidth), 999,
				"", 1, 0);

		/* XXX kludgy stylesheet turn off */
		STG_clean(0);

		send(docObj, "display", barWidth, 999);
		send(docObj, "show");

		pageHeight = send(docObj, "vspan");
		send(self(), "configShare");

		return;
	break;
	case "toDoInsert":
		insertObj[insertObjCount] = arg[1];
		insertObjCount++;
		return;
	break;
	case "show_request_by_child":
	case "post_request_by_child":
		send("www", "busy");

		if (arg[0] == "post_request_by_child") realMesg = "post";
		else realMesg = "show";

		if (torn == 1) destObj = self();
		else destObj = object("www");

		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);

		if (stat) stat = send("www.doc.view.pane", "historyRecord");

		send("www", "idle");
		return stat;
	break;
	case "setChildren":
		set("children", arg[1]);
		return;
	break;
	case "configShare":
		heightDiff = pageHeight - get("height");
		heightRatio =  float(heightDiff) / -100.0;
		if (heightDiff > 0) {
		  sliderSize = float(get("height")) / float(pageHeight) * 100;
		  sliderPos = float(pageYPos) / float(heightDiff) * -100;
		} else {
		  sliderSize = 100;
		  sliderPos = 0;
		}
		objectListSend("shownDepend", "_shownInfoH", 
				sliderPos, sliderSize);
		objectListSend("shownDepend", "setShownNotify", docObj);
		return;
	break;
	case "configSliderGeom":
		pageHeight = send(docObj, "vspan");
		send(self(), "configShare");
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
			send(docObj, "y", pageYPos);
		}
		send(self(), "configShare");
		return;
	break;
	case "config":
		if (send(parent(), "lbarEnabledP") == 0) return;
		usual();
		/* ask page object to do the calculation */
		send(docObj, "resize", get("width"), get("height"));
		pageYPos = send(docObj, "yP");
		pageHeight = send(docObj, "vspan");
		if (pageYPos + pageHeight < get("height")) {
			pageYPos = get("height") - pageHeight;
			send(docObj, "y", pageYPos);
		}
		send(self(), "configShare");
		configed = 1;
		return;
	break;
	case "update":
		pageObj = nthChild(0);
		pageHeight = arg[1];
		send(self(), "configShare");
		return;
	break;
	case "destroyDoc":
	case "destroyDoc_qualified":
		send(pageObj, "VW_event", "VIEW_OFF");
		send(pageObj, "visible", 0);
		send(pageObj, "freeSelf");
		pageObj = 0;
		return;
	break;
	case "addTool":
	case "removeTool":
	case "destroyTool":
		return send(parent(), arg[0], arg[1]);
	break;
	case "showSrc":
	case "reload":
	case "clone":
		return send(nthChild(0), arg[0]);
	break;
	case "whichPageP":
		return nthChild(0);
	break;
	case "heightP":
		return height();
	break;
	case "R": /* happens sometimes. blah */
	case "reportNextID":
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
