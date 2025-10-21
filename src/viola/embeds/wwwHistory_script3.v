
/*
  	print("wwwHistory: ");
	for (i = 0; i < arg[]; i++) print(arg[i], ", ");
	print("\n");
*/
	switch (arg[0]) {
	case "add":
		wwwHistory.list.tf("add", arg[1], arg[2]);
		return;
	break;
	case "back":
	case "prev":
	case "next":
	case "peek_prev":
	case "peek_next":
	case "toggle":
	case "peek_back":
		wwwHistory.list.tf(arg[0]);
		return;
	break;
	case "historyQuery":
		wwwHistory.list.tf(arg[0], arg[1]);
		return;
	break;
	case "visible":
		set("visible", arg[1]);
		return;
	break;
	case "dismiss":
		set("visible", 0);
		return;
	break;
	case "render":
		set("visible", 1);
		raise();
		return;
	break;
	case "config":
		windowName("ViolaWWW Travelal History");
	break;
	case "raise":
		raise();
		return;
	break;
	}
	usual();
