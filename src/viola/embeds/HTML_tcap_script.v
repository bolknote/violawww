
	switch (arg[0]) {
	case "D":
		text = get("label");
		if (align == 0) align = "center";
		send(parent(), "reportTitle", text, topP, align);
		return -1;
	break;
	case "config":
	case "R":
		return 0;
	break;
	case "AA":
		switch (arg[1]) {
		case "TOP":
			topP = 1;
		break;
		case "ALIGN":
			switch (arg[2]) {
			case "left":
				align = "westToEast";
			break;
			case "right":
				align = "eastToWest";
			break;
			case "top":
				align = "northToSouth";
			break;
			case "bottom":
				align = "southToNorth";
			break;
			case "center":
			default:
				align = "center";
			break;
			}
		break;
		}
		return;
	break;
	case "AI":
		switch (arg[1]) {
		case "TOP":
			topP = 0;
		break;
		case "ALIGN":
			align = "center";
		break;
		}
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
