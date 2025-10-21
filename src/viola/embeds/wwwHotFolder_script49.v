
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		send("wwwHotFolder.list.tf", "editComment");
		cursorShape("idle");
	break;
	}
	usual();
