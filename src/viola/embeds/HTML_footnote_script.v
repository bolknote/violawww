
	switch (arg[0]) {
	case 'i':
		new = send("HTML_footnote.ft", "clone");
		send(new, "make", get("label"));
		t = concat("\\o(", new, ")");
		return t;
	break;
	case "AI":
	case "AA":
		return;
	break;
	}
	usual();
