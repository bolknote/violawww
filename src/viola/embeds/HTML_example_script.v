
	switch (arg[0]) {
	case "mouseMove":
		hint = processMouseMove();
		if (prevHint != hint) {
			if (isBlank(hint)) www.mesg.tf("clear");
			else www.mesg.tf("show", hint);
		}
		prevHint = hint;
		return;
	break;
	case "leave":
		prevHint = 0;
		www.mesg.tf("clear");
		return;
	break;
	case "expose":
		return expose(arg[1], arg[2], arg[3], arg[4]);
	break;
	case "D": /* done */
		inPreP = send(parent(), "inPreP");
		if (inPreP) set("format", 0);
		set("content", get("label"));
		return (building_vspan() + 2);
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "XMP");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - get("x") - style[3]);
		set("content", trimEdgeQ(get("content")));/*bug*/
		vspan += set("height", building_vspan()) + style[1];
		render();
		return vspan;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "outputSGML":
		print("<XMP>", get("content"), "</XMP>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	case "make":
		inPreP = send(arg[1], "inPreP");
		if (inPreP) set("format", 0);
		return code_HTML_txt(arg);
	break;
	}
	usual();
