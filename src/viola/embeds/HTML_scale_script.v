
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send scale to parent primitive */
		p = parent();
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_rect", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_circle", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_oval", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_line", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_polygon", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_square", "getCurrentPrimitive");
		}
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_text", "getCurrentPrimitive");
		}
		if (p != "" && p != "0" && p != "(NULL)") {
			send(p, "setScale", scaleX, scaleY, scaleZ);
			/* Set SC flag on parent shape if SC attribute was present */
			if (hasSC == 1) {
				send(p, "setVariable", "_sc_scale", "1");
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
			scaleX = float(arg[2]);
		break;
		case "Y":
			scaleY = float(arg[2]);
		break;
		case "Z":
			scaleZ = float(arg[2]);
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
		scaleX = 1;
		scaleY = 1;
		scaleZ = 1;
		hasSC = 0;
		return;
	break;
	}
	usual();


