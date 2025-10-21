
	switch (arg[0]) {
	case "D":
		listItemObj = HTML_txtListItem("clone", self());
		h = send(listItemObj, "make", self(), 20, get("width") - 20);
		set("children", listItemObj);
		return h;
	break;
	case "searchAnchor":
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
		return code_HTML_txt(arg);
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
