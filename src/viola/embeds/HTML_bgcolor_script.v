
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "AA":
		print("[BGCOLOR] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "NAME":
			colorName = arg[2];
			/* Send immediately */
			print("[BGCOLOR] sending setBGColor to parent: ", colorName, "\n");
			send(parent(), "setBGColor", colorName);
		break;
		case "RGB":
			colorRGB = arg[2];
			/* Send immediately */
			print("[BGCOLOR] sending setBGColor (RGB) to parent: ", colorRGB, "\n");
			send(parent(), "setBGColor", colorRGB);
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
		print("[BGCOLOR] init: done\n");
		return;
	break;
	}
	usual();

