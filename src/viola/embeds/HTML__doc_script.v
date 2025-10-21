
/*
print("HTML__doc: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");print("...end\n");
*/
	switch (arg[0]) {
	case "expose":
		if (viewP == 0) return;
		usual();
		if (isHTML) render();
		return;
	break;
	case "shownPositionV":
		if (isHTML) return set("y", arg[1] * heightRatio);
		else return set("shownPositionV", arg[1]);
	break;
	case "inAnchor":
		return 0;
	break;
	case "scrollPageUp":
		if (isHTML) {
			y = get("y") - parentHeight;
			if (y < parentHeight - get("height"))
				y = parentHeight - get("height");
			set("y", y);
		} else {
			/* not yet implemented */
		}
		return;
	break;
	case "scrollPageDown":
		if (isHTML) {
			y = get("y") + parentHeight;
			if (y > 0) y = 0;
			set("y", y);
		} else {
			/* not yet implemented */
		}
		return;
	break;
	case "F": /* flush */
		h = 0;
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
				SGMLBuildDoc_span(), makeAnchor);
			makeAnchor = 0;
		}
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D":
		h = get("height");
		send(self(), "setStyles");
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(), 
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
				h, makeAnchor);
			makeAnchor = 0;
		}

		/* IMPORTANT KLUDGE: this is how this object knows whether 
		 * to behave like a single textfield (for ascii only text),
		 * or as container (for compound HTML objects).
		 */
		set("height", h);
/*after(1000, "www", "editMode", 1);*/
		return h;
	break;
	case "data":
		return compressSpaces(get("label"));
	break;
	case "inPreP":
		return 0;
	break;
	case 'T':
		/* arg[1] = y
		 * arg[2] = width
		 *
		 * put this check here rather than "D" since it may "D" time
		 * may not occur.
		 */
		if (objectListCount("children") > 0) {
			isHTML = 1;
			h = get("height");
			parentHeight = send(parent(), "heightP");
			heightDiff = h - parentHeight;
			if (heightDiff > 0) {
				heightRatio = float(heightDiff) / -100.0;
			} else {
				heightRatio = 0;
				h = parentHeight;
			}
			set("height", h);
			prevHeight = h;
		} else {
			prevHeight = get("height");
			h = building_vspan();
		}
		vspan = h;
		prevWidth = arg[2];
		return vspan;
	break;
	case "nameAndURL":
		docName = arg[1];
		docURL = arg[2];
		return;		
	break;
	case "setAnchor":
		makeAnchor = arg[1];
		return;
	break;
	case "query_docName":
		return docName;
	break;
	case "query_docURL":
		return docURL;
	break;
	case "searchAnchor":
		n = countChildren();
		if (n > 0) 
			for (i = 0; i < n; i++) {
				anchor = send(nthChild(i), 
						"searchAnchor", arg[1]);
				if (anchor != "") return anchor;
			}
		return "";
	break;
	case "gotoAnchor":
		if (tagID == arg[1]) return 0; /* special case */
		n = countChildren();
		if (n > 0)
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i),
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset;
			}
		return 0;
	break;
	case "follow_href":
		return send(parent(), "show_request_by_child", arg[1], docURL);
	break;
	case "post_href_n_data":
		return send(parent(), "post_request_by_child", arg[1], docURL,
							arg[2]);
	break;
	case "hintOn":
		return send(parent(), "hintOn", arg[1]);
	break;
	case "hintOff":
		return send(parent(), "hintOff");
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		set("y", 0);
		send(self(), "resize", arg[2], send(parent(), "heightP")); 
		return h;
	break;
	case "resize":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (..)
		 * Note: prevWidth & prevHeight also refers to viewer sizes
		 */
		set("width", arg[1]);
		if (isHTML) {
			n = countChildren();
			if (n) {
				xx = arg[1] - 5;
				h = 0;
				for (i = 0; i < n; i++)
					h += send(nthChild(i), "R", h, xx);
				vspan = h;
			} else {
				vspan = 1;
			}
			parentHeight = send(parent(), "heightP");
			if (vspan < parentHeight) vspan = parentHeight;

			heightDiff = vspan - parentHeight;
			if (heightDiff > 0) {
				heightRatio = float(heightDiff) / -100.0;
			} else {
				heightRatio = 0;
				vspan = parentHeight;
			}
			set("height", vspan);
		} else {
			set("height", arg[2]);
			set("content", get("content"));
			render();
			vspan = building_vspan();
		}
		prevWidth = arg[1];
		prevHeight = arg[2];
		return;
	break;
	case "resizeSelf":
		send(self(), "resize", 
			get("width"), send(parent(), "heightP"));
		send(parent(), "configSlider", get("y"), get("height"));
		return;
	break;
	case "VIEW_ON":
		for (i = 0; i < toolsCount; i++) send(tools[i], "visible", 1);
		return;
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		viewP = 1;
		send(self(), "resize", arg[1], arg[2]);
		set("visible", 1);
		if (get("window")) raise();

		deepObjectListSend("children", "visible", 1);

		for (i = 0; i < toolsCount; i++) {
			send(get("parent"), "addTool", tools[i]);
			send(tools[i], "visible", 1);
		}
		return;
	break;
	case "undisplay":
		viewP = 0;
		return;
	break;
	case "viewP":
		return viewP;
	break;
	case "configSelf":
	case "config":
		return;
	break;
	case "findTop":
		return self();
	break;
	case "placeID":
		/* this is clumsy. should be simplified with a primitive f() */
		/* find the caller (child) object's place in the obj list */
		cobj = arg[1];
		objPlace = -1;
		for (i = objectListCount_children() - 1; i >= 0; i--) {
			print("##/// i=", i, "  cobj=",  cobj, 
				"  nc=", nthChild(i), "\n");
			nobj = nthChild(i);
			if (cobj == nobj) {
				objPlace = i;
				print("#### objPlace = ",  i, "\n");
			}
		}
		objPlacePath = concat(objPlace, " ", arg[2]);
		print("#### objPlacePath = {",  objPlacePath, "}\n");
		return objPlacePath;
	break;
	case "change":
/*
print("!!############ obj = ",  arg[1], "\n");
print("!!############ objPlacePath = {",  arg[2], "}\n");
print("!!############ new data = {",  arg[3], "}\n");
*/
		objPlacePath = arg[2];
		newData = arg[3];

		cpa = nthWord(objPlacePath, 1);
/*print("!!############ childPosToAffect = {",  cpa, "}\n");*/
		newObjPlacePath = nthWord(objPlacePath, 2, 99);
/*print("!!############ new objPlacePath = {", newObjPlacePath, "}\n");*/

		send(nthChild(cpa), "change", newObjPlacePath, newData);
		send("www_com", "output_change", objPlacePath, newData);

		return;
	break;
	case "wedge_before":
		/* arg[1]	child 
		 * arg[2]	obj to insert after child
		 */
		objN = arg[1];
		objN1 = arg[2];

		ooi = 0;
		n = countChildren();
		for (i = 0; i < n; i++) {
			co = nthChild(i);
			if (co == objN) {
				oo[ooi] = objN1;
				ooi++;
			}
			oo[ooi] = co;
			ooi++;
		}
		for (i = ooi - 1; i >= 0; i--)
			objectListDelete_children(oo[i]);
		for (i = ooi - 1; i >= 0; i--)
			objectListPrepend_children(oo[i]);
		return;
	break;
	case "wedge_after":
		/* arg[1]	child 
		 * arg[2]	obj to insert after child
		 */
		objN = arg[1];
		objN1 = arg[2];

		ooi = 0;
		n = countChildren();
		for (i = 0; i < n; i++) {
			co = nthChild(i);
			oo[ooi] = co;
			ooi++;
			if (co == objN) {
				oo[ooi] = objN1;
				ooi++;
			}
		}
		print("old children list: ", get("children"), "\n");
		/* IDIOTIC WAY TO DELETE LIST */
		/*set("children", "");*/
		for (i = ooi - 1; i >= 0; i--) {
			print("delete OBJ from children list", oo[i], "\n");
			objectListDelete_children(oo[i]);
		}
		/* re set list in right order */
		for (i = ooi - 1; i >= 0; i--) {
			objectListPrepend_children(oo[i]);
		}
		print("new children list: ", get("children"), "\n");
		info();
		return;
	break;
	case "deleteChild":
		return objectListDelete_children(arg[1]);
	break;
	case "wedgeMeIn":
		/* arg[1]	object to wedge in
		 * arg[2]	side (0=upper, 1=lower)
		 */
		if (selectedObj) {
			print("#### selected Obj = ",  selectedObj, "\n");
			print("#### to wedge into Obj = ",  arg[1], "\n");
			send(selectedObj, "runAwayFromHome");
			if (arg[2] == 0) {
				print("#### upper side (wedge before)\n");
				send(self(), "wedge_before", 
					arg[1], selectedObj);
			} else {
				print("#### lower side (wedge after)\n");
				send(self(), "wedge_after", 
					arg[1], selectedObj);
			}
			selectedObj = 0;
			send(self(), "resizeSelf");
		} else {
			selectedObj = arg[1];
			print("#### selected Obj = ",  selectedObj, "\n");
		}
		return;
	break;

	case "CE_change":
		/* arg[1] 	CE objPath
		 * arg[2]	CE newData
		 */
		objPlacePath = arg[1];
		cpa = nthWord(objPlacePath, 1);
		newObjPlacePath = nthWord(objPlacePath, 2, 99);
/*
print("!!!!!!!!!!############ objPlacePath = {", objPlacePath, "}\n");
print("!!!!!!!!!!############ childPosToAffect = {",  cpa, "}\n");
print("!!!!!!!!!!############ new objPlacePath = {", newObjPlacePath, "}\n");
print("!!!!!!!!!!############ data = {", arg[2], "}\n");
*/
		send(nthChild(cpa), "CE_change", newObjPlacePath, arg[2]);
		return;
	break;
	case "lock":
/*
print("!!############ obj = ",  arg[1], "\n");
print("!!############ objPlacePath = {",  arg[2], "}\n");
*/
		objPlacePath = arg[2];
		send("www_com", "output_lock", objPlacePath);
		return;
	break;
	case "unlock":
/*
print("!!############ obj = ",  arg[1], "\n");
print("!!############ objPlacePath = {",  arg[2], "}\n");
*/
		objPlacePath = arg[2];
		send("www_com", "output_unlock", objPlacePath);
		return;
	break;
	case "CE_lock":
	case "CE_unlock":
		/* arg[1] 	CE objPath
		 */
		objPlacePath = arg[1];
		cpa = nthWord(objPlacePath, 1);
		newObjPlacePath = nthWord(objPlacePath, 2, 99);
		send(nthChild(cpa), arg[0], newObjPlacePath);
		return;
	break;
	case "widthP":
		return get("width");
	break;
	case "heightP":
		return get("height");
	break;
	case "reportTitle":
		docTitle = arg[1];
		return;
	break;
	case "yP":
		return get("y");
	break;
	case "y":
		return set("y", arg[1]);
	break;
	case "vspan":
		if (isHTML) return get("height");
		return vspan;
	break;
	case "reload":
		set("name", "dunsel");
		for (i = 0; i < toolsCount; i++)
			send(parent(), "destroyTool", tools[i]);
		send("www", "show", docURL);
		after(10000, self(), "visible", 0);
		after(10001, self(), "freeSelf");
		return 0;
	break;
	case "compact": /* just to handle bad HTML... */
	case "L": /*...*/
		/* should signal detection of bad HTML */
		return 0;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "show":
		set("visible", 1);
		render();
		if (get("window")) raise();

		for (i = 0; i < toolsCount; i++) send(tools[i], "visible", 1);

		relay_obj[relayIdx] = self();
		relay_event[relayIdx++] = "VIEW_OFF";

		return;
	break;
	case "search":
		if (isIndex == 0) {
			/* error cond, but do it anyway */ actionURL = docURL;
		} else if (isIndex == 1) {
			actionURL = docURL;
		} else {
			actionURL = isIndex;
		}
		cleanURL = send("parseHTTPAddress", "stripIndex", actionURL);
		return send(parent(), "show_request_by_child", 
				concat(cleanURL, '?', arg[1]), docURL);
	break;
	case "VIEW_OFF":
		for (i = 0; i < toolsCount; i++)
			send(parent(), "removeTool", tools[i]);
		return;
	break;
	case "blank":
		set("visible", 0);
		send(self(), "VIEW_OFF");
		return;
	break;
	case "queryAddress":
		return docURL;
	break;
	case "queryTitle":
		if (docTitle) return docTitle;
		return docName;
	break;
	case "isIndex":
		isIndex = 1;
		return;
	break;
	case "isIndexURL":
		isIndex = arg[1];
		return;
	break;
	case "queryIsIndex":
		return isIndex;
	break;
	case "historyRecord":
		send("www", "addToHistory", docName, docURL);
		return;
	break;
	case "toDoInsert":
		send(parent(), "toDoInsert", arg[1]);
		return;
	break;
	case "torn":
		/* Variable do not get cloned. So, set variables, 
		 * ie: parentHeight, hightDiff.. 
		 */
		orig = arg[1];

		docName = send(orig, "query_docName");
		docURL = send(orig, "query_docURL");

		send(self(), 'T', 0, get("width")); 
		return;
	break;
	case "output2File":
		send("res.getLineEntry", "show", 
			"Enter file name to save to document source to:", 
				"/tmp/out.html",
				self(), "gotOutputFileName");
		return;
 	break;
	case "gotOutputFileName":
		send("wwwSecurity", "getDocAndMoveItToSpecifiedPlace",
				docURL, arg[1]);
		send("www.mesg.tf", "show", 
			concat("Source saved to file: ", arg[1], "\n"));
		return;
 	break;
	case "showSrc":
		wwwSrc("showByURL", docURL);
		return;
 	break;
	case "reportAuthor":
		author = arg[1];
		return;
	break;
	case "configSideBar":
		if (sideBarURL != 0) {
			send(parent(), "linkSideBar",
				 sideBarURL, sideBarRatio, sideBarMaxWidth);
			return 1;
		}
		return 0;
	break;
	case "linkSideBar":
		hasSideBarP = 1;
		sideBarURL = arg[1];
		sideBarRatio = arg[2];
		sideBarMaxWidth = arg[3];
		return;
	break;
	case "queryAuthor":
		if (author == "") return 0;
		return author;
	break;
	case "editMode":
		editMode = arg[1];
		print("HTML__DOC: editMode=", editMode, "\n");
		n = countChildren();
		for (i = 0; i < n; i++) {
			anchor = send(nthChild(i), "editMode", editMode);
		}
		return;
	break;
	case "outlineSrc":
		send("www.mesg.tf", "show", 
			"Outliner not available for HTML\n");
		return;
	break;
	case "print":
/*
1 - the URL of those documents contain ";" telling the shell that
the instruction ended. you have to go out of viola, and enclose
it in quotation marks.
*/
		send("www.mesg.tf", "show", 
		    "Printing facillity not available for HTML.\n");
		return;
 	break;
	case "freeSelf":
		/* tools should be freed only when an object really is
		 * going away, and when the doc object is named 'dunsel'
		 * the doc is being reloaded.
		 */
/*		if (self() != "dunsel")
			for (i = 0; i < toolsCount; i++)
				send(tools[i], "freeSelf");
*/
		freeSelf();
		return;
	break;
	case "VW_relay":
		relay_obj[relayIdx] = arg[1];
		relay_event[relayIdx++] = arg[2];
		return 1;
	break;
	case "VW_event":
		event = arg[1];
		for (i = 0; i < relayIdx; i++)
			if (relay_event[i] == event) send(relay_obj[i], event);
		return;
	break;
	case "addTool":
		tools[toolsCount] = arg[1];
		toolsCount++;
		return;
	break;
	case "addTool_sticky":
		return send(parent(), "addTool", arg[1]);
	break;
	case "setStyles":
		tagPtr = STG_tagPtr("BODY");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
			i = STG_attr(tagPtr, "fontSlant");
		}
		return;
	break;
	case "outputSGML":
		print("<HTML>\n");
		n = countChildren();
		if (n) for (i = 0; i < n; i++)
				send(nthChild(i), "outputSGML");
		print("</HTML>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
/*\width {590}*/
/*\height {200}*/
