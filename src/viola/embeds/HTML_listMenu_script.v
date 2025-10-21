
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
		 * arg[2]	label
		 */
		return send(clone(cloneID()), "parent", arg[1]);
	break;
	case "parent":
		set("parent", arg[1]);
		return self();
	break;
	case "label":
		set("content", arg[1]);
		return;
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
