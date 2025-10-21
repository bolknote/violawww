
	switch (arg[0]) {
	case "D":
/*
		listItemObj = HTML_txtListItem("clone");
		h = send(listItemObj, "make", self(), 20, width() - 20);
		set("children", listItemObj);

		h = send(listItemObj, "make", self(), 20, width() - 20);
		print("*>>>>>>> h = ", h, "\n");
*/		
		return h;
	break;
	case "searchAnchor":
		if (get("content2") == arg[1]) return self();
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
		if (get("content2") == arg[1]) return y();
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
	}
	usual();
