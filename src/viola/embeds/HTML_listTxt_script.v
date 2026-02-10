
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
		www.mesg.tf("clear");
		prevHint = 0;
		return;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "P_in_listSep");
		vspan = style[0];
		set("width", get("width") - style[3]);
		set("content", get("content"));
		clearWindow();
		render();/*may be extraneous */
		vspan += set("height", building_vspan()) + style[1];
		return vspan;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	x (optional, overrides style)
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "P_in_listSep");
		vspan = style[0];
		if (arg[] >= 4) {
			set("x", arg[3]);
		} else {
			set("x", style[2]);
		}
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);
		set("content", get("content"));
		clearWindow();
		vspan += set("height", building_vspan()+2) + style[1];
		render(); /* render() affects building_vspan() ? */
		return vspan;
	break;
	case "make":
	 	/* arg[1]	parent
	 	 * arg[2]	data
	 	 * arg[3]	x
	 	 * arg[4]	width
	 	 * arg[5]	y
	 	 */
	 	set("parent", arg[1]);
	 	set("x", arg[3]);
	 	set("y", arg[5]);
	 	set("width", arg[4]);
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
	 	set("content", arg[2]);
	 	h = building_vspan();
	 	set("height", h);
	 	set("maxHeight", h);
	 	if (style == 0) style = SGMLGetStyle("HTML", "P_in_listSep");
		eventMask("+pointerMotion +leaveWindow");
	 	return style[0] + h + style[1];
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	return code_HTML_txt(arg);
