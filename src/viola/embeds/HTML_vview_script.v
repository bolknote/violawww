
	switch (arg[0]) {
	case "D":
		text = get("label");
		send(send(parent(), "findTop"), "VW_relay", self(),"VIEW_ON");
		send(send(parent(), "findTop"), "VW_relay", self(),"VIEW_OFF");
		return -1;
	break;
	case "VIEW_ON":
		print("interpreting: {", text, "}\n");
		interpret(text);
		return;
	break;
	case "VIEW_OFF":
	case "config":
	case "gotoAnchor":
		return "";
	break;
	}
	usual();
