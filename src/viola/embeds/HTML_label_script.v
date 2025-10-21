
	switch (arg[0]) {
	case "T":
		/* arg[1] = y
		 * arg[2] = width
		 */
		w = get("window");
		set("window", 0);
		set("width", arg[2] - 15);
		if (height() < 3) {
			print("height = ", height(), "\n");
			set("height", 999);
		}
		set("x", 10);
		set("window", w);
		set("content", get("label"));
		set("y", arg[1]);
		h = building_vspan() + 3;
		set("height", h);
		h += 6;
		return h;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		set("y", arg[1]);
		set("width", arg[2]);
		set("content", get("content"));
		vspan = building_vspan();
		set("height", vspan);
		render();
		return vspan;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
