
	switch (arg[0]) {
	case "keyPress":
		c = key();
		if (c == '\r') {
			send("www", "showHistoryDoc", trimEdge(currentLine()));
			render();
		} else {
			insert(c);
		}
		return;
	break;
	case "getURLFromClipBuffer":
		send("www", "showHistoryDoc", trimEdge(getSelection()));
		return;
	break;
	case "appendURLToHome":
		www.mesg.tf("alert", 
			    "Sorry, can't yet append to home page.");
		return;
	break;
	case "show":
		set("content", trimEdge(arg[1]));
		render();
		return;
	break;
	case "enter":
	case "leave":
		usual();
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "The current document address. Can edit URL there, then press return to follow.";
	break;
	}
	usual();
