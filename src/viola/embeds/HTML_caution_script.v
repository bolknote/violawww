
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
	case "D": /* done */
		inPreP = send(parent(), "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", get("label"));
		return (building_vspan() + 2);
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "CAUTION");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - get("x") - style[3]);
		set("content", get("content"));
		vspan += set("height", building_vspan()) + style[1];
		render();
		return vspan;
	break;
	case 'r':
		style = SGMLGetStyle("HTML", "CAUTION");
		vspan = style[0];
		set("width", get("width") - style[3]);
		set("content", get("content"));
		vspan += set("height", building_vspan()) + style[1];
		return vspan;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		color = getResource("Viola.foreground_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
	usual();
