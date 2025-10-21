
	switch (arg[0]) {
	case "expose":
	case "D":
		return 1;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "VR");
		set("y", arg[1] + style[0]);
		return 10;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "VR");
		after(1, self(), "fixHeight");
		return 10;
	break;
	case "fixHeight":
		ph = send(parent(), "heightP");
		set("height", ph - style[0] - style[1]);
		return;
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
	case "outputSGML":
		print("<VR>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
