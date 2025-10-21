
	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		style = SGMLGetStyle("HTML", "FIGDATA");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		vspan += get("height") + style[1];
		render();
		return vspan;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	w
		 * arg[3]	y
		 * arg[4]	src
		 */
		set("parent", arg[1]);
		set("width", arg[2]);
		style = SGMLGetStyle("HTML", "FIGDATA");
		set("y", style[0]);
		set("x", arg[3] + style[2]);

/*bleh*/	localSource = HTTPGet(arg[4]);
		fnNoExt = parseHTTPAddress("name", concat(localSource, ".ps"));
		system(concat("mv ", localSource, " /tmp/", fnNoExt, ".ps"));
		localSource = concat("/tmp/", fnNoExt, ".ps");
/*
print("arg[4]={", arg[4], "}\n");
print("localSource={", localSource, "}\n");
print("fnNoExt={", fnNoExt, "}\n");
*/
		if (arg[5] > 0) {
			after(arg[5], self(), 
				"loadData", localSource, arg[6], arg[7]);
			set("width", arg[6]);
			set("height", arg[7]);
			return height();
		} else {
			BITPLANES = 1;
			system("rm -f /tmp/ps2gif.tmp");
			saveFile("/tmp/ps2gif.tmp",
			   concat("(pstoppm.ps) run\n",
				  "80 80 ppmsetdensity\n",
				  "(/tmp/) ppmsetprefix\n",
				  "(", fnNoExt, ") ppm", BITPLANES, "run\n",
				  "80 80 ppmsetdensity\n"));
			system("cd /tmp; gs -DNODISPLAY -dSAFER -q < /tmp/ps2gif.tmp");

/*			system(concat("rm -f /tmp/", fnNoExt));
*/
			localFile = concat("/tmp/", fnNoExt, ".gif");
/*
print("localFile={", localFile, "}\n");
print("fnNoExt={", fnNoExt, "}\n");
*/
			system(concat("ppmtogif < /tmp/", 
					fnNoExt, ".ppm > ", localFile));

			system(concat("rm -f /tmp/", fnNoExt, ".ppm"));
			system("rm -f /tmp/ps2gif.tmp");

			/* to get the gif in its natural dimension */
			set("width", 0);
			set("height", 0);

			set("label", localFile);

			return height();
		}
	break;
	case "loadData":
		set("label", loadFile(arg[1]));
		render();
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
