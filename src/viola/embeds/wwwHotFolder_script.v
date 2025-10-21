
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		send("wwwHotFolder.list.tf", "goto");
		cursorShape("idle");
	break;
	}
	usual();
