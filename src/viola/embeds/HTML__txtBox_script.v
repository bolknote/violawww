
	switch (arg[0]) {
	case "make":
		/* arg[1]	txt
		 * arg[2]	width to use
		 */
		txt = arg[1];
		set("width", arg[2] - 50);
		set("content", txt);
		set("height", building_vspan());
		return height() + 5;
	break;
	case "R": /* resize */
		clearWindow();
		set("width", arg[1] - 50);
		set("content", txt);
		vspan = set("height", building_vspan());
		render();
		return vspan + 4;
	break;
	}
	usual();
