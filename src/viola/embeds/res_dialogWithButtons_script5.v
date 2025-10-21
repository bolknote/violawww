
	switch (arg[0]) {
	case "show":
		newDialogBox = clone(id);
		++id;

		windowName("Please respond to this dialog box.");

		send(newDialogBox, "show_mesg", arg[1]);
		for (argi = 2; argi < arg[]; argi += 2)
			send(newDialogBox, "adopt", arg[argi], arg[argi + 1]);
		send(newDialogBox, "visible", 1);

		return newDialogBox;
	break;
	case "showAt":
		set("x", arg[1]);
		set("y", arg[2]);
		set("width", arg[3]);
		set("height", arg[4]);

		newDialogBox = clone(id);
		++id;

		windowName("Please respond to this dialog box.");

		send(newDialogBox, "show_mesg", arg[5]);
		for (argi = 6; argi < arg[]; argi += 2)
			send(newDialogBox, "adopt", arg[argi], arg[argi + 1]);
		send(newDialogBox, "visible", 1);

		return newDialogBox;
	break;
	case "adopt":
		return send(nthChild(1), "adopt", arg[1], arg[2]);
	break;
	case "show_mesg":
		return send(nthChild(0), "show", arg[1]);
	break;
	case "done":
		set("visible", 0);
		after(1000, self(), "freeSelf");
		return;
	break;
	}
	usual();
