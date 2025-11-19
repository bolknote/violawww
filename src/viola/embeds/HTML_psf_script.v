
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'R': /* resize */
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "FIGDATA");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		vspan += get("height") + style[1];
		render();
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	y
		 * arg[4]	src
		 * arg[5]	delayP
		 * arg[6]	delayWidth
		 * arg[7]	delayHeight
		 * arg[8]	ismap
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		style = SGMLGetStyle("HTML", "FIGDATA");
		set("y", style[0]);
		set("x", arg[3] + style[2]);

		localSource = HTTPGet(arg[4]);

		if (arg[5] > 0) {
			after(arg[5], self(), 
				"loadData", localSource, arg[6], arg[7]);
			set("width", arg[6]);
			set("height", arg[7]);
			return height();
		} else {				
			localFile = concat(localSource, ".gif");

			system(concat("magick -density 80 -background white \"",
				localSource, "\" -alpha remove -alpha off -colors 256 \"",
				localFile,
			"\""));

			send("wwwSecurity", "rmTmpFile", localSource);

			/* to get the gif in its natural dimension */
			set("width", 0);
			set("height", 0);

			set("label", localFile);

			return height();
		}
	break;
	case "loadData":
		set("label", loadFile(arg[1]));
		render();
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
	case "freeSelf":
		if (isBlank(localFile) == 0) {
			send("wwwSecurity", "rmTmpFile", localFile);
		}
		return;
	break;
	}
	usual();
