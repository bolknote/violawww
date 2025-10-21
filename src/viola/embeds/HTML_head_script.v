
	switch (arg[0]) {
	case "D":
	case "F":
		return -1;
	break;
	case "data":
		SGMLBuildDoc_setBuff(-1);
		return get("label");
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "HEAD");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID": /* useless? */
			tagID = arg[2];
		break;
		}
		return;
	break;
	case "searchAnchor":
		if (tagID == arg[1]) return self();
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				anchor = send(nthChild(i), 
						"searchAnchor", arg[1]);
				if (anchor != "") return anchor;
			}
		}
		return "";
	break;
	case "gotoAnchor":
		if (tagID == arg[1]) return y();
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + y();
			}
		}
		return 0;
	break;
	case "inPreP":
	case "inAnchor":/*XXX*/
		return 0;
	break;
	case "findTop":
		return send(parent(), arg[0]);
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
