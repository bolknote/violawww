
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "AA":
		print("[SIZE] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "X":
			sizeX = int(arg[2]);
		break;
		case "Y":
			sizeY = int(arg[2]);
			/* Y is typically last - send to parent now */
			print("[SIZE] sending setSize to parent: ", sizeX, ",", sizeY, "\n");
			send(parent(), "setSize", sizeX, sizeY);
		break;
		case "Z":
			sizeZ = int(arg[2]); /* ignored for 2D */
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
		sizeX = 0;
		sizeY = 0;
		sizeZ = 0;
		print("[SIZE] init: done\n");
		return;
	break;
	}
	usual();

