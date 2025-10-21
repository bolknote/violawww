
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
		config();
		send(nthChild(0), "make", arg[2], arg[6]);
		return get("height") + 2;
	break;
	case "value":
	case "reset":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
