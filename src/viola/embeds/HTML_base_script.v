
        switch (arg[0]) {
        case "D":
                return -1;
        break;
        case "config":
	case "AI":
                return;
        break;
        case 'R':
                return 0;
        break;
	case "AA":
		switch (arg[1]) {
		case "HREF":
	                send(send(parent(), "findTop"), "baseURL", arg[2]);
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
