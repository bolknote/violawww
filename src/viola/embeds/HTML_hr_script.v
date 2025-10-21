
	switch (arg[0]) {
	case "expose":
	case "D":
		return 1;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "HR");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - get("x") - style[3]);
		vspan += get("height") + style[1];
		return vspan;
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
		print("<HR>\n");
		return;
	break;
	case "init":
		usual();
		color = getResource("Viola.foreground_doc");
		if (color) set("BGColor", color);
		return;
	break;
	}
	usual();
