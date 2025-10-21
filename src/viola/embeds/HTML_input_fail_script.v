
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height") + 2;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 */
		set("parent", arg[1]);
		set("width", arg[3]);
		set("height", arg[4]);
		return get("height") + 2;
	break;
	case "value":
		return get("content");
	break;
	case "reset":
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
