
	switch (arg[0]) {
	case "make":
		set("parent", arg[1]);
		ref = arg[2];
		bx = arg[3];
		by = arg[4];
		bw = arg[5];
		bh = arg[6];

		set("x", bx);
		set("y", by);
		set("width", bw);
		set("height", bh);
/*
		print("FIGA_ACTUAL: ref=", ref, "\n");
		print("FIGA_ACTUAL: x=", bx, "\n");
		print("FIGA_ACTUAL: y=", by, "\n");
		print("FIGA_ACTUAL: w=", bw, "\n");
		print("FIGA_ACTUAL: h=", bh, "\n");
*/
		/* document building routine turned them off by default,
		 * for efficiency, but here we want to use it for hints.
		 */
		eventMask("+enterWindow +leaveWindow");
		return -1;
	break;
	case "enter":
		send(parent(), "invertBox", bx, by, bx + bw, by + bh);
		top = send(parent(), "findTop");
		return send(top, "hintOn", 
			    concat("Entered hot spot for: ", ref));
	break;
	case "leave":
		send(parent(), "invertBox", bx, by, bx + bw, by + bh);
		return send(top, "hintOff");
	break;
	case "buttonRelease":
		return send(top, "follow_href", ref);
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
