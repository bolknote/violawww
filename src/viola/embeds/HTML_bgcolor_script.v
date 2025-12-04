
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "D":
		/* Send color to parent (GRAPHICS container) */
		p = parent();
		if (p == "" || p == "0" || p == "(NULL)") {
			p = send("HTML_graphics", "getCurrentGfx");
		}
		if (p != "" && p != "0" && p != "(NULL)") {
			if (colorName != "") {
				send(p, "setBGColor", colorName);
			} else if (colorRGB != "") {
				send(p, "setBGColor", colorRGB);
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

