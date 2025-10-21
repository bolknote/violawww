
	switch (arg[0]) {
	case "buttonPress":
/*		print("DUMPING CONTENT\n {", get("content"), "}\n");*/
	break;
	case "keyPress":
		c = key();
		if (c == '\r') {
			print("issue command:", currentLine(), "\n");
			if (isBlank(target())) target("res");
			ret = tweak(target(), currentLine());
			shell.obj.entry("show");
			insert('\r');
			shell.out.tf("insert", ret);
			return;
		} else {
			insert(c);
			return;
		}
	break;
	case "saveText":
		saveFile(".shellCmds", get("content"));
		return;
	break;
	case "loadText":
		path = accessible(".shellCmds");
		if (path != "") {
			set("content", loadFile(path));
			render();
		}
		return;
	break;
	case "init":
		path = accessible(".shellCmds");
		if (path != "") {
			set("content", loadFile(path));
		}
		if (isBlank(target())) target("res");
	break;
	case "expose":
		usual();
		return;
	break;
	}
	usual();
