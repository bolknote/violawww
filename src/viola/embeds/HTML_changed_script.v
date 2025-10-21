
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
		case "ID":
		case "IDREF":
		break;
		}
		return;
	break;
        case "gotoAnchor":
                return "";
        break;
	case "init":
		usual();
		color = getResource("Viola.background_doc");
		if (color) {
			set("BGColor", color);
			set("BDColor", color);
		}
		return;
	break; 
	}
        usual();
