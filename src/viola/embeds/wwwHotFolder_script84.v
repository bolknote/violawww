
	switch (arg[0]) {
	case "buttonRelease":
		if (isBlank(currentLine()) == 1) {
			bell();
		} else {
			oldIndex = index;
			deHighLight(index);
			index = cursorRow();
			highLight(index);
			if (get("window")) render();
/*
		print("Selected: currentLine=", currentLine(), "\n");
		print("Selected: index=", index, "\n");
		print("Selected: url=", HTTPHotListGet(0, index), "\n");
		print("Selected: comment=", HTTPHotListGet(1, index), "\n");
*/
			if (oldIndex == index) { /* cheezy double click*/
				send("wwwHotFolder", "busy");
				send("www", "show", HTTPHotListGet(0, index));
				send("wwwHotFolder", "idle");
				oldIndex = -1;
			}
		}
	break;
	case "goto":
		if (index > -1) {
			send("wwwHotFolder", "busy");
			send("www", "show", HTTPHotListGet(0, index));
			send("wwwHotFolder", "idle");
		}
		return;
	break;
	case "config":
		/* this is necessary due to the bug where content can't be
		 * set until the object has been configured... and this is
		 * a problem because a document may be "added" here before
		 * the widgets are configured.
		 */
		usual();
		send(self(), "load");
		return;
	break;
	case "save":
		HTTPHotListSave();
		return;
	break;
	case "load":
		tt = HTTPHotListGet(3);
		set("content", tt);
		if (get("window")) render();
		index = -1;
		return;
	break;
	case "add":
		url = send("www", "getCurrentDocURL");
		comment = send("www", "getCurrentDocTitle");
		HTTPHotListAdd(url, comment, date());
		HTTPHotListSave();
		send(self(), "load");
		return;
	break;
	case "delete":
		if (index != -1) {
			HTTPHotListDelete(index);
			HTTPHotListSave();
			send(self(), "load");
		} else {
			send("prompt", "show",
				"First select a hot list item, then delete.");
		}
		return;
	break;
	case "editComment":
		if (index != -1) {
			winPos = windowPosition();
			send("res.getLineEntry", "show", 
				"Enter new URL comment",
				HTTPHotListGet(1, index),
				self(),
				"newComment",
				winPos[0] + 20, winPos[1] + 20);
		} else {
			send("prompt", "show",
				"First select a hot list item, then edit.");
		}
		return;
	break;
	case "newComment":
		HTTPHotListChange(1/*comment*/, index, arg[1]);
		HTTPHotListSave();
		send(self(), "load");
		return;
	break;
	case "keyPress":
	case "enter":
	case "leave":
		return; 
	break;
	case "init":
		usual();
		previousDocIndx = -1;
		index = -1;
		count = 0;
		send(self(), "load");
		return;
	break;
	}
	usual();
