
	switch (arg[0]) {
	case "tic":
		invertLine(15,18, x, y);
		second = float(nthWord(date(), 6));
		d = second * 6.0 - 90.0;
		x = 8 * cos(d) + 15;
		y = 8 * sin(d) + 18;
		invertLine(15,18, x, y);
		after(500, self(), "tic");
		return;
	break;
	case "expose":
		usual();
		invertLine(15,18, x, y);
		return;
	break;
	case "init":
		usual();
		d = 270;
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
