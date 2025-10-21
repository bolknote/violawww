
/*
  	print("wwwHotFolder: ");
	for (i = 0; i < arg[]; i++) print(arg[i], ", ");
	print("\n");
*/
	switch (arg[0]) {
	case "addCurrent":
		send("wwwHotFolder.list.tf", "add");
		return;
	break;
	case "add":
		wwwHotFolder.list.tf("add", arg[1], arg[2]);
		return;
	break;
	case "toggle":
		wwwHotFolder.list.tf(arg[0]);
		return;
	break;
	case "historyQuery":
		wwwHotFolder.list.tf(arg[0], arg[1]);
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
	case "busy":
		cursorShape("busy");
		return;
	break;
	case "idle":
		cursorShape("idle");
		return;
	break;
	case "config":
		windowName("ViolaWWW Hot Lists");
	break;
	}
	usual();
