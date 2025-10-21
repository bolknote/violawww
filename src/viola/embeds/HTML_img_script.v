
	switch (arg[0]) {
	case "D":
		return 0;
	break;
	case 'i':
		/*local_src = cache_cheat("local", src);*/
		send("www.mesg.tf", "show", "Retrieving image data...");

		if (src) {
			if (ismap) {
				new = send("HTML__img", "clone");
				if (exist("HTML_txtAnchor"))
				  actionURL = send("HTML_txtAnchor", "url");
				else
				  actionURL = 0;
				send(new, "make", self(), src, actionURL);
				ret = concat("\\o(", new, ")");
				ismap = 0;
			} else {
				ret = concat("\\p(", src, ')');
			}
		} else {
			ret = "";
		}
		send("www.mesg.tf", "show", "Retrieving image data... Done.");
		return ret;
	break;
	case "AA":
		switch (arg[1]) {
		case "SRC":
			rel_url = arg[2];
			urlParts = HTTPCurrentDocAddrParsed(rel_url);
			src = concat(urlParts[0], "://", urlParts[1], 
				urlParts[2], urlParts[3]);
		break;
		case "HREF":
			href = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		case "ISMAP":
			ismap = 1;
		break;
		}
		return;
	break;
	case "AI":
	case "gotoAnchor":
		return 0;
	break;
	case "config":
	case "expose":
	case "render":
		return;
	break;
	}
	usual();
