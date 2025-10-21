
	switch (arg[0]) {
	case "expose":
		return expose();
	break;
	case "D":
		txt = send(parent(), "data");
		if (isBlank(txt)) {
			return 0;
		} else {
			set("content", txt);
			return (building_vspan() + 2);
		}
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
		set("width", arg[4]);
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", arg[2]);
		h = building_vspan() + 4;
		set("height", h);
		set("maxHeight", h);
		h += 4;
		inPreP = send(arg[1], "inPreP");
		return h;
	break;
	case "mouseMove":
		hint = processMouseMove();
		if (prevHint != hint) {
			if (isBlank(hint)) www.mesg.tf("clear");
			else www.mesg.tf("show", hint);
		}
		prevHint = hint;
		return;
	break;
	case "leave":
		prevHint = 0;
		www.mesg.tf("clear");
		return;
	break;
	case "R":
	case "clone":
	case "buttonRelease":
	case "config":
	case "gotoAnchor":
		return code_HTML_txt(arg);
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
