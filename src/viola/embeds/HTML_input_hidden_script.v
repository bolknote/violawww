
	switch (arg[0]) {
	case "R":
		return 0;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 */
		set("parent", arg[1]);
		defaultVal = arg[2];
		return 0;
	break;
	case "value":
		return defaultVal;
	break;
	case "reset":
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
