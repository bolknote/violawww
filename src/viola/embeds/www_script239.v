
	switch (arg[0]) {
	case "setShownNotify":
		set("shownNotify", arg[1]);
		return;
	break;
	case "kludgeRender":
		/* This is a kludge to get around a BUG */
		return after(1, self(), "render");
	break;
	}
	usual();
