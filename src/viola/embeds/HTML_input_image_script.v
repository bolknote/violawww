
	/* RIGHT NOW LIMITED TO GIF */
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height") + 2;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 */
/*		tagPtr = STG_tagPtr("INPUT");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		set("parent", arg[1]);
		defaultVal = arg[2];
		set("content", defaultVal);
		set("width", 0);
		set("height", 0);

		value = "";

		send("www.mesg.tf", "show", "Retrieving image data...");
		src = send(parent(), "src?");
		localFile = HTTPGet(src);
		print("input_image src=", src, "\n");
		print("input_image localFile=", localFile, "\n");
		set("label", localFile);
		set("width", get("width"));
		set("height", get("height"));
		print("input_image height=", get("height"), "\n");

		send("www.mesg.tf", "show", "Retrieving image data... Done.");
/*
		send("wwwSecurity", "rmTmpFile", localFile);
*/
		return get("height") + 1;
	break;
	case "buttonPress":
		xy = mouseLocal();
		x0 = xy[0];
		y0 = xy[1];
		set("FGColor", "red");
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);
		set("FGColor", "white");
		drawLine(x0, y0 - 5, x0, y0 + 5);
		drawLine(x0 + 5, y0, x0 - 5, y0);

		send(parent(), "acceptForm");
	break;
	case "value":
		return concat(x0, ",", y0);
	break;
	case "packValue":
		id = HTTPEncodeURL(arg[1]);
		return concat(id, ".x=", HTTPEncodeURL(x0), '&',
				id, ".y=", HTTPEncodeURL(y0));
	break;
	case "width?":
		return get("width");
	break;
	case "reset":
		set("content", defaultVal);
		clearWindow();
		render();
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		return;
	break;
	}
	usual();
