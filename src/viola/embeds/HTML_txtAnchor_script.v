
	switch (arg[0]) {
	case 'i':
		if (tagID) {
			send(parent(), "setAnchor", tagID);
			tagID = 0;
		}
		if (nthChild(0)) {
			return concat("\\o(", self(), ")");
		} else {
			if (send(get("parent"), "inPreP")) tt = get("label");
			else tt = compressSpaces(get("label"));

			if (url) {
				/* Use \v( for visited links, \b( for unvisited */
				visited = isURLVisited(url);
				/* Don't encode URLs that already have a protocol (contain :// near start) */
				protoPos = findPattern(url, "://");
				if (protoPos > 0 && protoPos <= 10) {
					encoded = url;
				} else {
					encoded = HTTPEncodeURL(url);
				}
			if (visited == 1) {
				t = concat("\\v(", tt,
					"\\v)\\e(", encoded, ") ");
			} else {
				t = concat("\\b(", tt,
					"\\b)\\e(", encoded, ") ");
			}
				url = 0;
				return t;
			} else {
				return tt;
			}
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
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = send("HTML_txt", "clone");
			objectListAppend_children(txtObj);

			if (send(get("parent"), "inPreP")) tt = get("label");
			else tt = compressSpaces(get("label"));

			h = send(txtObj, "make", self(),
				tt, style_p[3], 
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
		if (isBlank(get("label")) == 0) {
			if (style_p == 0) style_p = SGMLGetStyle("HTML", "P");
			txtObj = send("HTML_txt", "clone");
			objectListAppend_children(txtObj);

			if (send(get("parent"), "inPreP")) tt = get("label");
			else tt = compressSpaces(get("label"));

			h += send(txtObj, "make", self(),
				tt, style_p[3], 
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
			  vspan += send(nthChild(i), "R", vspan, xx);
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
	case "inAnchor":
/* trouble is, once txtAnchor is copied, 'url' and other info in variables
are lost. Solution send message to this object to have itself copied
(including the appropriate variables).
*/
		return url;
	break;
	case "expose":
	case "render":
		return;
	break;
	case "url":
		/* for <img ismap...> to ask */
		return url;
	break;
	case "findTop":
	case "findForm":
		return send(parent(), arg[0]);
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
