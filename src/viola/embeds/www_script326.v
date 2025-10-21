
	switch (arg[0]) {
	case "stat":
		if (arg[1] == -1) xxx = width();
		else xxx = float(arg[1]) / 100.0 * width();
		clearWindow();
		drawFillRect(0, 1, xxx, 3);
		flush();
		return;
	break;
	case "buttonRelease":
		print("IIIIIIIIIIIIII INTERRUPT TTTTTTTTTTT... sorry, you can't. yet.\n");
	break;
	case "clear":
		xxx = 0;
		clearWindow();
		flush();
		return;
	break;
	case "expose":
		if (xxx) drawFillRect(0, 1, xxx, 3);
		return;
	break;
	}
	usual();
