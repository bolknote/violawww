
	switch (arg[0]) {
	case "D":
/*RAW		tmpf = HTTPGet(docURL);
		if (tmpf == 0) {
			set("content", 
				concat("Failed to include ", docURL));
			set("BGColor", "red");
			set("FGColor", "white");
		} else {
			set("content", loadFile(tmpf));
		}
		h = building_vspan();
		set("height", h);
*/
		eventMask("+pointerMotion +leaveWindow +buttonRelease");
		docURL = send("normalizeURL", "normalizeURL", docURL);
		h = 10;
		send(send(parent(), "findTop"), "toDoInsert", self());
		return h;
	break;
	case "reinsert":
		set("height", 0);/*to prevent padding*/

		oldObj = nthChild(0);
		objectListDelete_children(oldObj);

		handler = wwwFormatDetect("type", docURL);
		paneObj = self();
		cursorShape("busy");
					/* just to generate unique name */
		docName = concat(self(), makeTempFile());
		docObj = send("wwwHandlerDispatch", "dispatch",
				handler, 0 /* no do post */,
				docURL, docName, paneObj,
				get("width"), 9999999,
				anchor, 1, 0 /* no post data */);
		h = send(docObj, "vspan");
		set("children", docObj);
		send(docObj, "visible", 1);
		set("height", h);
		cursorShape("busy");
		if (prevHeight != h)
			send(send(parent(), "findTop"), "resizeSelf");
		prevHeight = h;

		send(oldObj, "freeSelf");
		after(reInsertDelay, self(), "reinsert");
		return;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "INSERT");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		if (nthChild(0) != 0) {
			vspan += send(nthChild(0), 'R', 0, width() - 4);
			set("height", vspan);
		}
		prevHeight = vspan;
		vspan += style[1];
		return vspan;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "HREF":
			docURL = arg[2];
		break;
		case "BORDER":
			set("BDColor", "black");
		break;
		case "ASIS":
			raw = 1;
		break;
		case "AFTER":
			reInsertDelay = int(arg[2]);
			after(reInsertDelay, self(), "reinsert");
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		}
		return;
	break;
	case "insert":
		handler = wwwFormatDetect("type", docURL);
		paneObj = self();
					/* just to generate unique name */
		docName = concat(self(), makeTempFile());
		docObj = send("wwwHandlerDispatch", "dispatch",
				handler,
				0 /* no do post */,
				docURL,
				docName,
				paneObj,
				get("width"),
				get("height"),
				anchor,
				1, 
				0 /* no post data */);
		h = send(nthChild(0), "vspan");
		set("height", h);
		return;
	break;
	case "toDoInsert":
		/* relay for nested <insert>s */
		send(send(parent(), "findTop"), "toDoInsert", arg[1]);
		return;
	break;
	case "setChildren":
		set("children", arg[1]);
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "config":
		return;
	break;
	case "heightP":
		return get("height");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
