
        switch (arg[0]) {
        case 'i':
                /* HTML+ CHANGED tag with ID/IDREF markers:
                 * <changed id=X> opens a marked region
                 * <changed idref=X> closes a marked region
                 * The actual marking is done by SGMLBuildDoc_enterChanged/leaveChanged
                 * which wrap all subsequent text in \m(...\m)
                 */
                return "";
        break;
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
		/* ID/IDREF are handled directly in sgml.c for proper timing */
		switch (arg[1]) {
		case "ID":
			id = arg[2];
		break;
		case "IDREF":
			idref = arg[2];
		break;
		}
		return;
	break;
        case "gotoAnchor":
                return "";
        break;
        case "inPreP":
                return send(get("parent"), "inPreP");
        break;
        case "expose":
        case "render":
                return;
        break;
	case "init":
		usual();
		return;
	break; 
	}
        usual();
