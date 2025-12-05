
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send size to parent primitive */
		p = parent();
		/* Fallback only for BUTTON which has broken parent() */
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_button", "getCurrentPrimitive");
		}
		if (p != "" && p != "0" && p != "(NULL)") {
			send(p, "setSize", sizeX, sizeY);
			/* Set SC flag on parent shape if SC attribute was present */
			if (hasSC == 1) {
				send(p, "enableSCSize");
			}
		}
		return 0;
	break;
	case "AA":
		switch (arg[1]) {
		case "SC":
			/* SC attribute enables peer discovery for sync */
			hasSC = 1;
			discoveryEnable();
		break;
		case "X":
			sizeX = int(arg[2]);
		break;
		case "Y":
			sizeY = int(arg[2]);
		break;
		case "Z":
			sizeZ = int(arg[2]);
		break;
		}
		return;
	break;
	case "AI":
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		sizeX = 0;
		sizeY = 0;
		sizeZ = 0;
		hasSC = 0;
		return;
	break;
	}
	usual();

