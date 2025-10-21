
	switch (arg[0]) {
	case "D":
		txt = send(parent(), "data");
		if (isBlank(txt)) {
			return 0;
		} else {
			listItemObj = HTML_txtListItem("clone");

			set("children", listItemObj);

			h = send(listItemObj, "make", self(), txt,
					40, width() - 40);

			/* to number or not? */
			if (send(parent(), 'N')) {
				bulletObj = HTML_listNum("make", self());
			} else {
				bulletObj = HTML_listBullet("make", self());
			}
			objectListAppend_children(bulletObj);

			return h;
		}
	break;
	case 'R': /* resize */
		if (style == 0) style = SGMLGetStyle("HTML", "LI");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);
		vspan = send(nthChild(0), "R", vspan, width() - 40);
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		/* arg[2]	data
		 * arg[3]	x
		 * arg[4]	width
		 * arg[5]	y
		 */
		set("parent", arg[1]);
		set("x", arg[3]);
		set("y", arg[5]);

		txt = arg[2];

		listItemObj = HTML_txtListItem("clone");

		set("children", listItemObj);

		h = send(listItemObj, "make", self(), txt,
				40, arg[4] - 40);

		/* to number or not? */
		if (send(parent(), 'N')) {
			bulletObj = HTML_listNum("make", self());
		} else {
			bulletObj = HTML_listBullet("make", self());
		}
		objectListAppend_children(bulletObj);

		set("width", arg[4]);
		set("height", h);
		return h;
	break;
	case "itemN":
		send(nthChild(1), "label", arg[1]);
		return;
	break;
	case "noBullet":
		w = width();
		set("label", "");
		clearWindow();
		set("width", w);
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
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
