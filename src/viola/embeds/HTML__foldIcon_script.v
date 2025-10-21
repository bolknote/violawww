
	switch (arg[0]) {
	/* terrible hack */
	case "folderOpenXBM":
		return "#define folderOpen_width 16
#define folderOpen_height 16
static char folderOpen_bits[] = {
   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0x08, 0x80, 0xfc, 0x87,
   0x02, 0x88, 0x02, 0x88, 0x04, 0x90, 0x04, 0x90, 0x08, 0xa0, 0x08, 0xa0,
   0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};";
	break;
	case "folderClosedXBM":
		return "#define folderClosed_width 16
#define folderClosed_height 16
static char folderClosed_bits[] = {
   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0xf8, 0xbf, 0x04, 0xa0,
   0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xc0,
   0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};";
	break;
	case "buttonRelease":
		folded = send(parent(), "toggleFolded");
		if (folded)
			set("label", send("HTML__foldIcon", "folderClosedXBM"));
		else
			set("label", send("HTML__foldIcon", "folderOpenXBM"));
		render();
	break;
	case "setFolded":
		folded = arg[1];
		if (folded)
			set("label", send("HTML__foldIcon", "folderClosedXBM"));
		else
			set("label", send("HTML__foldIcon", "folderOpenXBM"));
		render();
		return;
	break;
	case "make":
		return send(clone(cloneID()), "parent", arg[1]);
	break;
	case "parent":
		set("parent", arg[1]);
		return self();
	break;
	case "init":
		usual();
		foldInfo = 1;
		set("label", send("HTML__foldIcon", "folderOpenXBM"));
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
