
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
		set("content", get("label"));
		return (building_vspan() + 2);
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "EXAMPLE");/*XXX*/
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - get("x") - style[3]);
		set("content", get("content"));
		vspan += set("height", building_vspan()) + style[1];
		render();
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
		return;
	break;
	}
	usual();
