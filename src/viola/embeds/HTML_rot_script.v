
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send rotation to parent primitive */
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
		if (p != "" && p != "0" && p != "(NULL)") {
			if (hasX == 1) {
				send(p, "setRotX", myRotX);
			}
			if (hasY == 1) {
				send(p, "setRotY", myRotY);
			}
			if (hasZ == 1) {
				send(p, "setRotZ", myRotZ);
			}
		}
		return 0;
	break;
	case "AA":
		switch (arg[1]) {
		case "X":
			myRotX = float(arg[2]);
			hasX = 1;
		break;
		case "Y":
			myRotY = float(arg[2]);
			hasY = 1;
		break;
		case "Z":
			myRotZ = float(arg[2]);
			hasZ = 1;
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
		myRotX = 0;
		myRotY = 0;
		myRotZ = 0;
		hasX = 0;
		hasY = 0;
		hasZ = 0;
		return;
	break;
	}
	usual();


