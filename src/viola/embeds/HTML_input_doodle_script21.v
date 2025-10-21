
	switch (arg[0]) {
	case "mouseMove":
		if (penDownP) {
			x0 = x1;
			y0 = y1;
			x1 = arg[1];
			y1 = arg[2];
			drawLine(x0, y0, x1, y1);

			segments[count] = 0;	/* sickie language flaw */
			seg = segments[count];
			seg[0] = x0;
			seg[1] = y0;
			seg[2] = x1;
			seg[3] = y1;
			segments[count] = seg;

			count++;
			return;
		}
	break;
	case "buttonPress":
		penDownP = 1;
		x0 = mouseX();
		y0 = mouseY();
		x1 = x0;
		y1 = y0;
	break;
	case "buttonRelease":
		penDownP = 0;
	break;
	case "clear":
		count = 0;
		clearWindow();
		return;
	break;
	case "dump":
		for (i = 0; i < count; i++) {
			seg = segments[i];
			print(i, ":", seg[0], ",", seg[1], 
				" ",  seg[2], ",", seg[3],
				"\n");
		}
		return;
	break;
	case "getVar":
		tt = "";
		for (i = 0; i < count; i++) {
			seg = segments[i];
			tt = concat(tt, seg[0], ",", seg[1], 
				    ",",  seg[2], ",", seg[3],
				    ";\n");
		}
		return tt;
	break;
	case "expose":
		for (i = 0; i < count; i++) {
			seg = segments[i];
			drawLine(seg[0], seg[1], seg[2], seg[3]);
		}
		return;
	break;
	case "setup":
		penDownP = 0;
		return;
	break;
	case "init":
		usual();
		penDownP = 0;
		color = getResource("Viola.foreground_doc");
		if (color) {
			set("BDColor", color);
			set("FGColor", color);
		}
		return;
	break;
	}
	usual();
