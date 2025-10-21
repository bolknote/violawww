
	switch (arg[0]) {
	case "make":
		/* arg[1]	insertObj
		 * arg[2]	width to use
		 * arg[3]	height to use
		 */
		set("width", arg[2]);
		set("height", arg[3]);
		objectListAppend_children(arg[1]);
		return self();
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
