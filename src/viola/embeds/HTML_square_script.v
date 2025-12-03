
	switch (arg[0]) {
	case "expose":
		print("[SQUARE] expose: drawing at ", posX, ",", posY, " size ", sizeX, "\n");
		if (sizeX > 0) {
			if (filled) {
				drawFillRect(posX, posY, posX + sizeX, posY + sizeX);
			}
			drawRect(posX, posY, posX + sizeX, posY + sizeX);
		}
		return;
	break;
	case "D":
		print("[SQUARE] D: done\n");
		return 0;
	break;
	case "R":
		print("[SQUARE] R: ignored (inline)\n");
		return 0;
	break;
	case "AA":
		print("[SQUARE] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		}
		return;
	break;
	case "AI":
		return;
	break;
	case "setPos":
		print("[SQUARE] setPos: ", arg[1], ",", arg[2], "\n");
		posX = int(arg[1]);
		posY = int(arg[2]);
		return;
	break;
	case "setSize":
		/* For SQUARE, use the smaller of X and Y to keep it square */
		print("[SQUARE] setSize: ", arg[1], ",", arg[2], "\n");
		sizeX = int(arg[1]);
		sizeY = int(arg[2]);
		if (sizeY < sizeX) sizeX = sizeY;
		return;
	break;
	case "setFGColor":
		print("[SQUARE] setFGColor: ", arg[1], "\n");
		set("FGColor", arg[1]);
		return;
	break;
	case "setBDColor":
		print("[SQUARE] setBDColor: ", arg[1], "\n");
		set("BDColor", arg[1]);
		return;
	break;
	case "setFilled":
		print("[SQUARE] setFilled: ", arg[1], "\n");
		filled = int(arg[1]);
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
		sizeX = 0;
		sizeY = 0;
		filled = 1;
		color = getResource("Viola.foreground_doc");
		if (isBlank(color) == 1) color = "black";
		set("FGColor", color);
		set("BDColor", color);
		print("[SQUARE] init: done\n");
		return;
	break;
	}
	usual();

