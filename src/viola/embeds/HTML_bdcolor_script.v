
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "AA":
		print("[BDCOLOR] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "NAME":
			colorName = arg[2];
			/* Send immediately */
			print("[BDCOLOR] sending setBDColor to parent: ", colorName, "\n");
			send(parent(), "setBDColor", colorName);
		break;
		case "RGB":
			colorRGB = arg[2];
			/* Send immediately */
			print("[BDCOLOR] sending setBDColor (RGB) to parent: ", colorRGB, "\n");
			send(parent(), "setBDColor", colorRGB);
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
		print("[BDCOLOR] init: done\n");
		return;
	break;
	}
	usual();

