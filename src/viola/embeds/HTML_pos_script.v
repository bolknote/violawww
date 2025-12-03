
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "AA":
		print("[POS] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "X":
			posX = int(arg[2]);
		break;
		case "Y":
			posY = int(arg[2]);
			/* Y is typically last - send to parent now */
			print("[POS] sending setPos to parent: ", posX, ",", posY, "\n");
			send(parent(), "setPos", posX, posY);
		break;
		case "Z":
			posZ = int(arg[2]); /* ignored for 2D */
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
		print("[POS] init: done\n");
		return;
	break;
	}
	usual();

