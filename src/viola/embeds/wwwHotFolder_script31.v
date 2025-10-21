
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		send("wwwHotFolder.list.tf", "add");
		cursorShape("idle");
	break;
	}
	usual();
