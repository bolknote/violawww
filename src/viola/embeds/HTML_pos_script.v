
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send position to parent primitive */
		p = parent();
		/* Fallback only for BUTTON which has broken parent() */
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_button", "getCurrentPrimitive");
		}
		if (p != "" && p != "0" && p != "(NULL)") {
			send(p, "setPos", posX, posY);
			/* Set SC flag on parent shape if SC attribute was present */
			if (hasSC == 1) {
				send(p, "enableSCPos");
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
			posX = int(arg[2]);
		break;
		case "Y":
			posY = int(arg[2]);
		break;
		case "Z":
			posZ = int(arg[2]);
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
		posX = 0;
		posY = 0;
		posZ = 0;
		hasSC = 0;
		return;
	break;
	}
	usual();

