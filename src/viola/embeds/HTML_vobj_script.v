
	switch (arg[0]) {
	case 'i':
		if (tagID) {
			send(parent(), "setAnchor", tagID);
			tagID = 0;
		}
		if (url) {
			t = concat(" \\b(", compressSpaces(get("label")),
					"\\b)\\e(", HTTPEncodeURL(url), ") ");
			url = 0;
			return t;
		} else {
			return compressSpaces(get("label"));
		}
	break;
	case "AA":
		switch (arg[1]) {
		case "NAME":
			tagID = arg[2];
		break;
		case "HREF":
			url = arg[2];
		break;
		}
		return;
	break;
	case "F":
		h = 0;
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h = send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
				SGMLBuildDoc_span(), makeAnchor);
			makeAnchor = 0;
		}
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D":
		set("content2", self());/*a kludge to deal with cloning*/
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			h += send(txtObj, "make", self(),
				compressSpaces(get("label")),
				style_p[3], 
				get("width") - style_p[3] - style_p[2],
				h, makeAnchor);
			makeAnchor = 0;
		}
		set("height", h);
		return h;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "P");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);

		vspan = 1;
		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
			  vspan += send(nthChild(i), 'R', vspan, xx);
		}
		set("height", vspan);
		return vspan;
	break;
	case "copyObj":
		url = send(arg[1], "url");
		return 0;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
