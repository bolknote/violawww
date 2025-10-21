
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
		send(parent(), "body", self());
		/* just return something, and fill in data later. 
		 * But must be big enough (>2) so that textfield widget
		 * won't wine at the height being too small and not
		 * allow for formatting when the data comes.
		 */
		return 1;
	break;
	case 'R': /* resize */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "DD");
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
		 * arg[5]	y
		 */
		set("x", arg[3]);
		set("y", arg[5]);
		set("width", arg[4]);
		set("height", 8);/* big enough to allow text to be put in */
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", arg[2]);
		h = building_vspan();
		set("height", h);
		set("maxHeight", h);
		h += 4;
		return h;
	break;
	case "config":
	case "gotoAnchor":
	case "buttonRelease":
		return code_HTML_txt(arg);
	break;
	case "clone":
		return clone(cloneID());
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
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
