
	switch (arg[0]) {
	case "cloneTarget":
		new = tweak(target(), "clone(1);");
		print("newobj=", new, "\n");
		tweak(new, "set(\"parent\", \"\");");
		send(new, "info");
		send(new, "visible", 1);
		return;
	break;
	}
	usual();
