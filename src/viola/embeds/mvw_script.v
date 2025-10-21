
	switch (arg[0]) {
	case "stat":
		if (inProgress == 0) {
			clearWindow();
			inProgress = 1;
		}
		fillArc(5, 2, w, h, 0, arg[1] * 3.6);
		flush();
		return;
	break;
	case "clear":
		inProgress = 0;
		clearWindow();
		render();
		return;
	break;
	case "config":
	case "init":
		usual();
		h = get("height") - 5;
		w = h;
		return;
	break;
	}
	usual();
