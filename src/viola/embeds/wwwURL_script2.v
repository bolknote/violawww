
	switch (arg[0]) {
	case "open":
		/* arg[1]	default entry
		 * arg[2]	caller, the obj to return result to
		 * arg[3]	x
		 * arg[4]	y
		 * arg[5]	width
		 * arg[6]	height
		 */
		newObj = clone(id);
		id++;
		return send(newObj, "_open", 
			    arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);
	break;
	case "_open":
		caller = arg[2];

		set("x", arg[3]);
		set("y", arg[4]);
		set("width", arg[5]);
		set("height", arg[6]);

		windowName("Attention, please...");
		send(newObj, "visible", 1);
		set("visible", 1);
		send(nthChild(1), "show", arg[1]);
		return self();
	break;
	case "_cut":
	case "_clear":
		send(nthChild(1), arg[0]);
		return;
	break;
	case "_ok":
		set("visible", 0);
		send(caller, "gotURLToOpen", send(nthChild(1), "contentP"));
		return;
	break;
	case "_cancel":
		set("visible", 0);
		return;
	break;
	}
	usual();
