
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send color to parent primitive */
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
			if (colorName != "") {
				send(p, "setBDColor", colorName);
			} else if (colorRGB != "") {
				send(p, "setBDColor", colorRGB);
			}
		}
		return 0;
	break;
	case "AA":
		switch (arg[1]) {
		case "NAME":
			colorName = arg[2];
		break;
		case "RGB":
			colorRGB = arg[2];
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
		colorName = "";
		colorRGB = "";
		return;
	break;
	}
	usual();

