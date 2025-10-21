
	switch (arg[0]) {
	case "expose":
		return expose();
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	img url
		 * arg[3]	action url
		 */
		actionURL = arg[3];

		set("parent", arg[1]);

		/* to get the gif in its natural dimension */
		set("width", 0);
		set("height", 0);

		send("www.mesg.tf", "show", "Retrieving image data...");

		urlParts = HTTPCurrentDocAddrParsed(arg[2]);
		imgURL = concat(urlParts[0], "://", urlParts[1], 
				urlParts[2], urlParts[3]);

		set("label", imgURL, imgURL);
		set("height", get("height"));

		send("wwwSecurity", "rmTmpFile", localFile);
		send("www.mesg.tf", "show", "Retrieving image data... Done.");
		return self();
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
		if (actionURL != 0) {
			send("www", "show", 
				concat(actionURL, "?", x0, ",", y0));
		} else {
			if (top == 0) top = send(parent(), "findTop");
			ref = concat(send(top, "query_docURL"), "?",
					x0, ",", y0);
			send(top, "follow_href", ref);
		}
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
