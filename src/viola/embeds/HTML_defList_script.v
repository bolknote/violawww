
	switch (arg[0]) {
	case "head":
	case "body":
		toMake = arg[0];
		txtObj = arg[1];
		return;
	break;
	case "F": /* flush */
		return send(self(), 'm', "F");
	break;
	case "D": /* done */
		return send(self(), 'm', "D");
	break;
	case "m": /* make */
		if (arg[1] == "D") SGMLBuildDoc_setBuff(0);
		else SGMLBuildDoc_setBuff(-1);/*???*/
		t = compressSpaces(get("label"));
		if (isBlank(t) == 1) {
			if (arg[1] == "F") {
				return 1;
			} else if (arg[1] == "D") {
				return get("height");
			} else {
				return 1;
			}
		}

		switch (toMake) {
		default:/* in case the DefList doesn't start with either
			 * <DT> or <DD>
			 */
		case "head":
			if (styleDT == 0) styleDT = SGMLGetStyle("HTML", "DT");
			y = get("height");
			txtH = send(txtObj, "make", self(), 
				t, styleDT[2], 
				get("width") - styleDT[3] - styleDT[2], y);
		break;
		case "body":
			if (styleDD == 0) styleDD = SGMLGetStyle("HTML", "DD");
			y = get("height");
			txtH = send(txtObj, "make", self(), 
				t, styleDD[2], 
				get("width") - styleDD[3] - styleDD[2], y);
		break;
		}
		if (arg[1] == "F") h = set("height", txtH);
		else if (arg[1] == "D") h = set("height", y + txtH);
		else h = set("height", txtH);
		return h;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "DL");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);

		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "data":
		/* In case there is <P> in DefList */
		return send(self(), "m", "D");
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "AI":
	case "inAnchor":
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
