
	switch (arg[0]) {
	case "expose":
	case "R":
		return 0;
	break;
	case "AA":
		print("[POINT] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "ID":
			tagID = arg[2];
		break;
		case "X":
			pointX = int(arg[2]);
		break;
		case "Y":
			pointY = int(arg[2]);
			/* Y is last - send to parent polygon now */
			print("[POINT] sending addPoint to parent: ", pointX, ",", pointY, "\n");
			send(parent(), "addPoint", pointX, pointY);
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
		pointX = 0;
		pointY = 0;
		print("[POINT] init: done\n");
		return;
	break;
	}
	usual();

