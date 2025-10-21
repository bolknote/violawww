
	switch (arg[0]) {
	case "tic":
		if (inView == 0) return;
		set("FGColor", "black");
		render();
		after(1000, self(), "toc");
		return;
	break;
	case "toc":
		if (inView == 0) return;
		set("FGColor", "white");
		render();
		after(1000, self(), "tic");
		return;
	break;
	case "inView":
		inView = arg[1];
		return;
	break;
	}
	usual();
