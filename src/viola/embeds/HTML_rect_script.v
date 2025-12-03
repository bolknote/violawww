
	switch (arg[0]) {
	case "getShapeType":
		return "rect";
	break;
	case "getX":
		return posX;
	break;
	case "getY":
		return posY;
	break;
	case "getW":
		return sizeX;
	break;
	case "getH":
		return sizeY;
	break;
	case "getFG":
		return fgColor;
	break;
	case "expose":
		return;
	break;
	case "D":
		/* Register with parent container */
		p = parent();
		print("[RECT] D: done, self=", self(), " parent=", p, "\n");
		/* Only register if parent is a GRAPHICS container */
		if (findPattern(p, "HTML_graphics") >= 0) {
			print("[RECT] D: registering with GRAPHICS parent\n");
			send(p, "addChild", self());
		}
		return 1; /* Keep object alive */
	break;
	case "R":
		return 0;
	break;
	case "AA":
		print("[RECT] AA: ", arg[1], "=", arg[2], "\n");
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
		print("[RECT] setPos: ", arg[1], ",", arg[2], "\n");
		posX = int(arg[1]);
		posY = int(arg[2]);
		return;
	break;
	case "setSize":
		print("[RECT] setSize: ", arg[1], ",", arg[2], "\n");
		sizeX = int(arg[1]);
		sizeY = int(arg[2]);
		return;
	break;
	case "setFGColor":
		fgColor = arg[1];
		return;
	break;
	case "setBDColor":
		set("BDColor", arg[1]);
		return;
	break;
	case "setFilled":
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
		fgColor = "black";
		print("[RECT] init: done\n");
		return;
	break;
	}
	usual();

