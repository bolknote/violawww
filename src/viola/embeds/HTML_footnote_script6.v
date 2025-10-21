
	switch (arg[0]) {
	case "buttonPress":
		set("BDColor", "red");
	break;
	case "buttonRelease":
		res.dialogWithButtons("show", get("content"), "OK", "");
		set("BDColor", "LemonChiffon1");
	break;
	case "make":
		set("content", arg[1]);
		return;
	break;
	case "outputSGML":
		print("<FOOTNOTE>", get("content"), "</FOOTNOTE>\n");
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		color = getResource("Viola.borderColor_doc");
		if (color) set("BDColor", color);
		return;
	break;
	}
	usual();
