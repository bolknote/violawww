
	switch (arg[0]) {
	case "make":
		set("content", arg[1]);		
		set("width", arg[2]);		
		set("height", arg[3]);		
		return self();
	break;
	case "clone":
		return clone(arg[1]);
	break;
	}
	usual();
