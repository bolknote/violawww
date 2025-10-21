
	/* Failure notice.
	 * This object is used to display insertions that failed. 
	 * See HTML_vobjf.v for usage example.
	 */
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
	case "make":
		/* arg[1]	parent
		/* arg[2]	width
		 * arg[3]	message
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", arg[3]);
		set("height", building_vspan());
		return (building_vspan() + 2);
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		set("y", arg[1]);
		set("x", 0);
		set("width", arg[2] - get("x"));
		set("content", get("content"));
		vspan = set("height", building_vspan());
		render();
		return get("height");
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
