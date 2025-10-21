
	switch (arg[0]) {
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
	case "D":
		send(parent(), "head", self());
		return 1;
	break;
	case 'R': /* resize */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "DT");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		set("content", get("content"));
		vspan += set("height", building_vspan()+2) + style[1];
		render();
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	data
		 * arg[3]	x
		 * arg[4]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "DT");
		vspan = style[0];
		set("x", arg[3]);
		set("y", arg[5]);
		set("width", arg[4]);
		set("height", 8);/* big enough to allow text to be put in */
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", arg[2]);
		h = building_vspan();
		set("height", h+2);
		set("maxHeight", h);
		h += vspan + style[1];
		return h;
	break;
	case "config":
	case "gotoAnchor":
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

	case "buttonRelease":
		return code_HTML_txt(arg);
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
