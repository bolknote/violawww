
	switch (arg[0]) {
	case "show":
		/* arg[1]	display message
		 * arg[2]	default entry
		 * arg[3]	caller, the obj to return result to
		 * arg[4]	returning message token
		 * arg[5]	optional x position
		 * arg[6]	optional y position
		 */
		newObj = clone(id);
		id++;
		if (arg[] > 5)
		  return send(newObj, "_show", arg[1], arg[2], arg[3], arg[4],
				arg[5], arg[6]);
		else 
		  return send(newObj, "_show", arg[1], arg[2], arg[3], arg[4]);
	break;
	case "_show":
		if (arg[] > 5) {
			set("x", arg[5]);
			set("y", arg[6]);
		}
		send(nthChild(0), "show", arg[1]);
		send(nthChild(1), "show", arg[2]);
		caller = arg[3];
		returnMessage = arg[4];

		windowName("Attention, please...");
		send(newObj, "visible", 1);
		set("visible", 1);
		return self();
	break;
	case "_ok":
		set("visible", 0);
		send(caller, returnMessage, send(nthChild(1), "contentP"));
		return;
	break;
	case "_cancel":
		set("visible", 0);
		return;
	break;
	}
	usual();
