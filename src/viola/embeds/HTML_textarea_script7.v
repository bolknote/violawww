
/*
print(">>> HTML__textarea: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("...end\n");
*/
	switch (arg[0]) {
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("y", arg[1]);
		set("width", arg[2] - 2);
		config();
		return get("height") + 2;
	break;
	case 'r':/* BROKEN */
		set("width", width() - 10);
		set("content", get("content"));
		h = building_vspan();
		if (h < heightByRows) h = heightByRows;
		vspan += set("height", h) + style[1];
		render();
		return vspan + 2;
	break;
	case "make":
		/* arg[1]	tagID
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 */
/*		set("parent", arg[1]);*/

		tagID = arg[1];
		defaultVal = arg[2];
		set("width", arg[3]);
		set("height", arg[4]);

		config();

		send(nthChild(0), "make", arg[2]);

		if (form == 0) form = send(parent(), "findForm");
		if (form == 0) {
			print("HTML_select: can't find form. self=",
				self(), "\n");
		} else {
			send(form, "regInputer", self());
		}
		return get("height") + 2;
	break;
	case "value":
		return concat(HTTPEncodeURL(tagID), "=",
				HTTPEncodeURL(send(nthChild(0), "value")));
	break;
	case "reset":
		return send(nthChild(0), arg[0]);
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		objWidth = 300;
		objHeight = 150;
		return;
	break;
	}
	usual();
