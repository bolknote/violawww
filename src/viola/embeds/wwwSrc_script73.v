
	switch (arg[0]) {
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "enter":
	case "keyPress":
	case "leave":
		return;
	break;
	case "getAndShow":
		cursorShape("busy");
		localFile = HTTPGet(arg[1]);
		set("content", loadFile(localFile));
		send("wwwSecurity", "rmTmpFile", localFile);
		cursorShape("idle");
		return;
	break;
	case "saveAs":
		send("res.getLineEntry", "show", 
			"Enter file path to save source HTML into:",
			"", self(), "saveIntoThisFile");
		return;
	break;
	case "saveIntoThisFile":
		if (saveFile(trimEdge(arg[1]), get("content")) == 0) {
			winPos = windowPosition();
			res.dialogWithButtons("showAt", 
				winPos[0] + 20, winPos[1] + 20,
				500, 80,
				concat("Failed to save source in file:\n", 
					trimEdge(arg[1])),
				"Dismiss", "");
		}
		return;
	break;
	case "print":
		tempf = makeTempFile();
		saveFile(tmpf, get("content"));
		/* need to get printing command */
		system(concat("lpr ", tempf));
		return;
	break;
	case "contentP":
		return get("content");
	break;
	}
	usual();
