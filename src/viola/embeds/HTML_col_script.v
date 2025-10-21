
	switch (arg[0]) {
	case "F": /* flush */
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = SGMLBuildDoc_span();

			xx = get("width") / 2;
			col = _col % 2;
			indent = col * xx;

			txtH = send(txtObj, "make", self(), 
				compressSpaces(get("label")),
				indent, xx, h, 0);
			if (col == 1) {
				set("height", h + txtH);
			} else {
				set("height", h);
				return -1;
			}
		}
		return get("height");
	break;
	case "D":
		h = send(self(), 'R', get("y"), get("width"));
		set("height", h);
		return h;
	break;
	case 'L':
		return "D";
	break;
	case "col":
		_col++; /* for listSep to query, to know its place */
		return (_col - 1) % 2;		/*XXX dude, implement++ */
	break;
	case "colEnd":
		return 1;
	break;
	case "inPreP":
		return 0; /* little point account for PRE here */
	break;
	case "itemWidth":
		return get("width") / 2;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "DIR");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);
		set("x", style[2]);

		_col = 0;

		n = countChildren();
		if (n) {
			xx = get("width") / 2;
			for (i = 0; i < n;) {
				col = i % 2;
				indent = col * xx;
				h = send(nthChild(i), 'R', vspan, xx, indent);
				i++;
				if ((col == 1) || (i == n)) vspan += h;
			}
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "data":
/*		SGMLBuildDoc_setBuff(-1);*/
		return get("label");
	break;
	case "compact":
		return 1;
	break;
	case "searchAnchor":
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return self();
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
		if (tagIDCount > 0)
			for (i = 0; i < tagIDCount; i++)
				if (tagIDs[i] == arg[1]) return get("y");
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
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
