
	switch (arg[0]) {
	case "D":
		h = SGMLBuildDoc_span();
		set("height", h);
		return h;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		vspan = -1;
		set("x", 30);		/*XXX*/
		set("y", arg[1]);
		set("width", arg[2] - get("x"));

		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
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

		h = 1;

		/* in case there's text before <LI> */
		SGMLBuildDoc_setBuff(-1);
		/* ^ needed for this case due to the inserting of this object
		 * by HTML_listSep (at its Flush time).
		 */

		txt = get("label");
		if (isBlank(txt) == 0) {
			new = HTML_txt("clone");
			w = get("width");
			h = send(new, "make", self(),
				compressSpaces(txt), 0, w, 0, 0);
			objectListAppend_children(new);
			send(parent(), "specialInsertOccured");
		}
		return h;
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
		if (id == arg[1]) return get("y");
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + get("y");
			}
		}
		return 0;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "L":
	case "compact":
		return 0;
	break;
	case "listDepth":
		return send(parent(), "listDepth");
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "C":/* useless-- but keep to keep viola quiet */
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
