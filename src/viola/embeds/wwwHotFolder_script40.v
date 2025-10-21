
	switch (arg[0]) {
	case "buttonRelease":
		cursorShape("busy");
		send("wwwHotFolder.list.tf", "delete");
		cursorShape("idle");
	break;
	}
	usual();
