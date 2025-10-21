
/* must have no children obj since this obj is spec'ed as
 * an inlined object in the HTML_style.c.
 */
/*
print(">>> HTML_textarea: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("...end\n");
*/
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'i':
		new = send("HTML__textarea", "clone");
		send(new, "make", tagID, get("label"), objWidth, objHeight);
		t = concat("\\o(", new, ")");

		tagID = "";
		objWidth = 300;
		objHeight = 100;

		return t;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "SIZE":
			i = findPattern(arg[2], ',');
			if (i == -1) {
				size_cols = int(arg[2]);
				/* extra size to allow for scrollbar */
				objWidth = size_cols * textWidth(0, "n") + 20;
				objHeight = 100;
			} else {
				size_cols = int(nthChar(arg[2], 0, i-1));
				objWidth = size_cols * textWidth(0, 'n');

				defaultRows = int(nthChar(arg[2], i+1, 99));
				objHeight = defaultRows * 15;

/*				set("width", objWidth);
				set("height", defaultRows * 15);
*/
			}
/*
print("TEXTAREA SET: objWidth=", objWidth, "\n");
print("TEXTAREA SET: objHeight=", objHeight, "\n");
*/
		break;
		case "COL":
		case "COLS":
			objWidth = (int(arg[2]) * textWidth(0, "n")) + 20;
/*print("TEXTAREA SET: objWidth=", objWidth, "\n");
*/
		break;
		case "ROW":
		case "ROWS":
/*print("TEXTAREA SET:----------\n");
*/
			objHeight = int(arg[2]) * 15; /*iffy*/
/*
print("TEXTAREA SET: arg[2]=", arg[2], "\n");
print("TEXTAREA SET: objHeight=", objHeight, "\n");
*/
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		}
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "clone":
		return clone(cloneID());
	break;
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
/*
print("TEXTAREA MAKE: arg width=", arg[3], "\n");
print("TEXTAREA MAKE: arg height=", arg[4], "\n");
*/
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
	case "init":
		usual();
		objWidth = 300;
		objHeight = 150;
		return;
	break;
	}
	usual();
