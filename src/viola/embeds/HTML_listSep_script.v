
	switch (arg[0]) {
	case "expose":
		return;
	break;
	case "D":
		if (send(parent(), "compact")) saveSpace = 3;
		if (specialInsertOccured == 1) {
			h = send(self(), 'R', get("y"), get("width"), 
				 get("x")) - saveSpace;
		} else {
			h = get("height") - saveSpace;
		}
		SGMLBuildDoc_setBuff(0);
		/*^^ necessary, else the "First item" will appear twice in */
		/*
		<UL>
		<LI>First item
		<P>
		<LI>Second item
		</UL>
		*/
		if (isBlank(get("label")) == 0) {
			listType = send(parent(), 'L');
			if (first == 0) {
				first = 1;
				switch (listType) {
				case 'U':	/* UL */
					bulletObj = HTML_listBullet("make", 
								    self());
					objectListAppend_children(bulletObj);
					x_offset = 30;
					objResizeSkip = 1;
				break;
				case 'O':	/* OL */
				/*bulletObj = HTML_listNum_oval("make",
						      self());*/
				bulletObj = HTML_listNum("make",self());
				objectListAppend_children(bulletObj);
				x_offset = 30;
				objResizeSkip = 1;
			break;
			default:
				x_offset = 35;
				break;
				}
			}
			if (listTxt_style == 0) 
				listTxt_style = SGMLGetStyle("HTML", 
							     "P_in_listSep");
			txtObj = HTML_listTxt("clone");
			objectListAppend_children(txtObj);

			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				x_offset,
				get("width") - x_offset - listTxt_style[3],
				h, 0);
		}
		set("height", h + 2);
		return h;
	break;
	case "F":
		/* create and set insertObject before "D", so flush this obj
		 */
		if (parent() == 0) return;
		listType = send(parent(), 'L');
		y = SGMLBuildDoc_span();
		if (first == 0) {
			first = 1;
			switch (listType) {
			case 'U':	/* UL */
				bulletObj = HTML_listBullet("make", self());
				objectListAppend_children(bulletObj);
				x_offset = 30;
				objResizeSkip = 1;
			break;
		case 'O':	/* OL */
			bulletObj = HTML_listNum("make", self());
		/*bulletObj = HTML_listNum_oval("make", self());*/
			objectListAppend_children(bulletObj);
			x_offset = 30;
			objResizeSkip = 1;
		break;
			default:
				x_offset = 30;
			break;
			}
		}
		switch (listType) {
		case 'U':	/* UL */
			listItemContainer = HTML_listItem("clone");
			w = get("width") - 30;
			txtH = send(listItemContainer, "make", self(), 
					30, y, w);
			SGMLBuildDoc_insertObj(listItemContainer, w);

			return -1;
		break;
		case 'O':	/* OL */
			listItemContainer = HTML_listItem("clone");
			w = get("width") - 40;
			txtH = send(listItemContainer, "make", self(), 
					30, y, w);
			SGMLBuildDoc_insertObj(listItemContainer, w);

			return -1;
		break;
		case 'D':	/* DIR */
			listItemContainer = HTML_listItem("clone");
			w = get("width") - 30;
			txtH = send(listItemContainer, "make", self(), 
					30, h, w);
			SGMLBuildDoc_insertObj(listItemContainer, w);

			return -1;
		break;
		case 'M':	/* MENU */
		default:
			listItemContainer = HTML_listItem("clone");
			w = get("width") - 30;
			txtH = send(listItemContainer, "make", self(), 
					30, h, w);
			SGMLBuildDoc_insertObj(listItemContainer, w);
			return -1;
		break;
		}
	break;
	case 'R': /* resize */
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	x (optional)
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "LI");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("width", arg[2] - style[3]);
		if (arg[] == 4) set("x", arg[3]);
		h = 0;
		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = objResizeSkip; i < n; i++)
				h += send(nthChild(i), 'R', h, xx,
					  x_offset) - saveSpace;
		}
		vspan += h;
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "AA":
	case "AI":
	case "config":
		return;
	break;
	case "itemN":
		send(nthChild(0), "label", arg[1]);
		/* Widen x_offset if label needs more space */
		w = textWidth(1, arg[1]) + 4;
		if (w > x_offset) x_offset = w;
		return;
	break;
	case "listDepth":
		return send(parent(), "listDepth");
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "specialInsertOccured":
		specialInsertOccured = 1;
		return;
	break;
	case "searchAnchor":
	case "gotoAnchor":
		return 0;
	break;
	case "setAnchor":
		return send(parent(), "setAnchor", arg[1]);
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
