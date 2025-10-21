
	switch (arg[0]) {
	case "visible":
		if (arg[1] == 1) {
			if (get("visible") == 1) {
				set("visible", 0);
				return;
			}
			vwWinPos = send("www", "winPosition");
			set("x", vwWinPos[0] + 20);
			set("y", vwWinPos[1] + 130);
			send("wwwAbout.fld.states", "inView", 1);
			send("wwwAbout.fld.states", "tic");
		}
	break;
	case "dismiss":
		send("wwwAbout.fld.states", "inView", 0);
		set("visible", 0);
		return;
	break;
	}
	usual();
