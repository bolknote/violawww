
	switch (arg[0]) {
	case "make":
		/* arg[1]	txt
		 * arg[2]	width to use
		 * arg[3]	FGColor (optional)
		 * arg[4]	BGColor (optional)
		 * arg[5]	BDColor (optional)
		 */
		txt = arg[1];
		set("width", arg[2] - 50);
		eventMask("+pointerMotion +leaveWindow");
		
		/* Apply colors if provided */
		argc = arg[];
		if (argc > 2) {
			if (arg[3]) {
				set("FGColor", arg[3]);
			}
			if (arg[4]) {
				set("BGColor", arg[4]);
			}
			if (arg[5]) {
				set("BDColor", arg[5]);
			}
		}
		
		set("content", txt);
		h = building_vspan();
		if (h < 32) h = 32;
		set("height", h);
		return h;
	break;
	case 'R': /* resize */
		clearWindow();
		set("width", arg[1] - 50);
		set("content", txt);
		h = building_vspan();
		if (h < 32) h = 32;
		set("height", h);
		render();
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
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	return code_HTML_txt(arg);
