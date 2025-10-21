
	print("@@@@@@ HTML_insertee clsss = field: args: ");
	for (i =0; i < arg[]; i++) print(arg[i], ", ");
	print("====================\n");
	print("insertee self=", self(), "\n");

	switch (arg[0]) {
	case "D":
/*print("insertee: D height=", height(), "\n");*/
		h = SGMLBuildDoc_span();
		set("height", h);
print("insertee: D h=", h, "\n");
		return h;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		vspan = -1;
		set("x", 30);		/*XXX*/
		set("y", arg[1]);
		set("width", arg[2] - x());

		n = countChildren();
		if (n) {
			xx = width();
			for (i = 0; i < n; i++) {
print("insertee: child=", nthChild(i), "\n");
print("insertee: before vspan=", vspan, "\n");
				vspan = vspan 
					+ send(nthChild(i), 'R', vspan, xx);
print("insertee: after vspan=", vspan, "\n");
			}
		}
		set("height", vspan);
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	x
		 * arg[3]	y
		 * arg[4]	width
		 */
		set("parent", arg[1]);
		set("x", arg[2]);
		set("y", arg[3]);
		set("width", arg[4]);
	print("insertee height=", height(), "\n");
		return;
	break;
	case "noBullet":
		return;
	break;
	case "searchAnchor":
		if (id == arg[1]) return self();
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
		if (id == arg[1]) return y();
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
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
