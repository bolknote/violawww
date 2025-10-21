
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
		set("width", send(parent(), "wP"));
		inPreP = send(parent, "inPreP");
		if (inPreP) set("format", 0);
		set("content", text);
		h = building_vspan() + 3;
		set("height", h);
		set("maxHeight", h);
		h += 6; /* allow for gapH/V & border*/
		return h;
	break;
	case "R": /* resize */
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	x (optional)
		 */
		clearWindow();
		set("y", arg[1]);
		set("width", arg[2]);
		set("content", get("content"));
		h = set("height", building_vspan() + 4);
		render();
		return h;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	data
		 * arg[3]	x
		 * arg[4]	width
		 * arg[5]	listType
		 */
		set("parent", arg[1]);
		set("x", arg[3]);
		set("width", arg[4]);
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		eventMask("+pointerMotion +leaveWindow");
		set("content", arg[2]);
		h = building_vspan() + 4;
		set("height", h);
		set("maxHeight", h);
		if (arg[5] == 'D') set("BGColor", "LemonChiffon2");
		h += 4;
		eventMask("+pointerMotion +leaveWindow");
		return h;
	break;
	case 'i':
		if (text) text = concat(text, get("label"));
		else text = get("label");
		return;
	break;
	case 'A':
		/* arg[1]	object to absorb
		 */
		if (text) text = concat(text, send(arg[1], 'i'));
		else text = send(arg[1], 'i');
		return 0;
	break;
	case 'P':
		set("parent", arg[1]);
		return h;
	break;
	case "buttonRelease":
		usual();
		if (charButtonMask() > 0) {
			ref = HTTPDecodeURL(nextTag());
			if (ref) {
				if (shiftKeyP()) {
					www.mesg.tf("show",
						concat("Dest: ", ref));
				} else {
					setRevVideoFlag(1);
					send(send(parent(), "findTop"), 
						"follow_href", ref);
					setRevVideoFlag(0);
				}
			}
		} else {
			/* lets user complete cut/paste */
		}
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
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
