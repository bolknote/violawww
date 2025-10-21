
	switch (arg[0]) {
	case "D":
/*		send(parent(), 'A', get("label"));
*/
		return 0;
	break;
	case "data":
		return get("label");
	break;
	case "ref":
		return ref;
	break;
	case "setRef":
		ref = arg[1];
	break;
	case "gotoAnchor":
		return 0;
	break;
	}
	usual();
