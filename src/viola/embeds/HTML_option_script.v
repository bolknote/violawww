
	switch (arg[0]) {
	case 'i':
		send(parent(), "option", varDefault, get("label"), checked);
		varDefault = "";
		checked = 0;
		return "";
	break;
	case "gotoAnchor":
	case "AI":
		return 0;
	break;
	case "AA":
		switch (arg[1]) {
		case "VALUE":
			varDefault = arg[2];
		break;
		case "SELECTED":
		case "CHECKED":
			checked = 1;
		break;
		}
		return;
	break;
	case "expose":
	case "render":
		return;
	break;
	case "outputSGML":
		print("<OPTION");
		if (varDefault) print(" VALUE=\"", varDefault, "\"");
		if (checked) print(" SELECTED");
		print(">\n");
		print(get("content"));
		print("\n");
	break;
	}
	usual();
