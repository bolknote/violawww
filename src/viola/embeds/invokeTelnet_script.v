
	switch (arg[0]) {
	case "buttonRelease":
		invokeExample("invoke", caller);
	break;
	case "new":
		/* arg[1]	caller
		 * arg[2]	parent
		 * arg[3]	x
		 * arg[4]	y
		 */
		return send(clone(cloneID(), "build", 
				arg[1], arg[2], arg[3], arg[4]));
	break;
	case "build":
		/* arg[1]	caller
		 * arg[2]	parent
		 * arg[3]	x
		 * arg[4]	y
		 */
		caller = arg[1];
		set("parent", arg[2]);
		set("x", arg[3] + 2);
		set("y", arg[4]);
		set("visible", 1);
		return get("name");
	break;
	}
	usual();
