
	switch (arg[0]) {
	case "show":
		set("content", loadFile(arg[1]));
/*
print("loading file >>>>>>>", arg[1], "<<<\n");
print("content >>>>>>>", get("content"), "<<<\n");
*/
		return;
	break;
	case "contentP":
		return get("content");
	break;
	}
	usual();
