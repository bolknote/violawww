
	/* reminder: get rid of obsolete cases
	 */
	switch (arg[0]) {
	case "shownPositionV":
		set("y", arg[1] * heightRatio);
		return;
	break;
	case "resize":
		/* arg[1]	width
		 * arg[2]	height
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "HTML");
		set("y", style[0]);
		set("width", arg[1] - x() - style[3]);

		parentHeight = send(get("parent"), "heightP");
		if (vspan >= parentHeight) {
			set("height", vspan);
		} else {
			set("height", parentHeight);
		}
		return get("height");
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		set("visible", 1);
		if (get("window")) raise();
		if (arg[1] != prevWidth) {
			/* need to re-format */
			send(self(), "resize", arg[1], arg[2]);
		} else if (arg[2] != prevHeight) {
			/* just adjust window height */
			send(self(), "resize", arg[1], arg[2]);
		}
		return;
	break;
	case "config":
		vspan = building_vspan();
		return;
	break;
	case 'T':
		/* arg[1] = y
		 * arg[2] = width
		 */
		h = get("height");
		parentHeight = send(parent(), "heightP");
		heightDiff = h - parentHeight;
		if (heightDiff > 0) {
			heightRatio =  float(heightDiff) / -100.0;
		} else {
			heightRatio = 0;
			h = parentHeight;
			set("height", h);
		}
		prevWidth = arg[2];
		prevHeight = parentHeight;
		return h;
	break;
	case "buttonRelease":
		return HTML_txt(arg);
	break;
	case "yP":
		return y();
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "widthP":
		return get("width");
	break;
	case "heightP":
		return height();
	break;
	case "reportTitle":
		docTitle = arg[1];
		return;
	break;
	case "vspan":
		return vspan;
	break;
	case "y":
		return set("y", arg[1]);
	break;
	case "heightP":
	case "vspan":
		return height();
	break;
	case "build":
		/* arg[1]	sourcefile
		 * arg[2]	parent
		 * arg[3]	name
		 * arg[4]	width
		 */
		docURL = arg[1];
		docName = arg[3];

		set("parent", arg[2]);
		set("name", arg[3]);
		set("width", arg[4]);

		stat = set("HTMLAddress", docURL);

		if (stat == 0) return 0;

/*		set("children", docObj);*/
/*		send(docObj, "nameAndURL", docName, docURL);*/
/*		tweak(docObj, concat("set(\"name\", \"", docName, "\");"));*/
/*		vspan = send(docObj, "vspan");*/

		/* this is a temporary kludge, where the HTML object's window
		 * is as big as the document vspan. 
		 */
		vspan = building_vspan();
		set("height", vspan);

		return self();
	break;
	case "historyRecord":
		wwwHistory("add", get("HTMLTitle"), get("HTMLAddress"));
		return;
	break;
	case "reload":
		clearWindow();
		purgeCache(self());
		set("HTMLAddress", get("HTMLAddress"));
		render();
		return;
	break;
	case "search":
		cursorShape("busy");
		search(arg[1]);
		cursorShape("idle");
		return;
	break;
	case "keyPress":
/*		www.doc.ctrl.tf("focus");*/
		return;
	break;
	case "save":
		tmp = "/tmp/out.html";	/* later, use dialog box */
		cmd = concat("www -n ", 
				get("HTMLAddress"), " > ", 
				tmp);
		system(cmd);
		return;
	break;
	case "queryAddress":
		return get("HTMLAddress");
	break;
	case "queryTitle":
		return get("HTMLTitle");
	break;
	case "queryIsIndex":
		return get("HTMLIsIndex");
	break;
	case "tree":
		/* produce a n-level anchors tree by recursively fetching
		 * anchor links 
		 */
		return;
	break;
	case "showSrc":
		wwwSrc("showByURL", get("HTMLAddress"));
/*		wwwHTMLSrc("show", 
			get("name"), get("HTMLAddress"), get("HTMLSource"));
*/
		return;
	break;
	case "updateSrc":
		/* arg[1]	new HTMLSource
		 */
		tmp = concat(makeTempFile(), ".html");
		saveFile(tmp, arg[1]);
		set("HTMLAddress", tmp);
		render();
		return;
	break;
	case "outlineSrc":
		www.mesg.tf("show", "Outliner not available for HTML.");
		return;
	break;
	case "print":
		/* This facility could be much better. But for now...
		 * Todo:
		 *	convert to TeX
		 * 	  or generate postscript (use variable width font)
		 * 	use internal formatter (no need to call www)
		 * 	use cached HTMLSource (no need to fetch html file)
		 */
		lprCmd = environVar("WWW_LPR");
		if (isBlank(lprCmd)) lprCmd = "lpr ";
		tmp = concat(makeTempFile(), ".html");
		www.mesg.tf("flash", 
			concat("Printing command: ", lprCmd));
		system(concat("www -n ", get("HTMLAddress"), " > ", tmp));
		system(concat(lprCmd, " ", tmp));
		send("wwwSecurity", "rmTmpFile", tmp);
		return;
 	break;
	case "output2File":
		res.getLineEntry("show", 
			"Enter file name to save to document source to:", 
				"/tmp/out.html",
				self(), "gotOutputFileName");
		return;
 	break;
	case "gotOutputFileName":
		dumpFile = HTTPGet(docURL);
		system(concat("mv ", dumpFile, " ", arg[1]));
		www.mesg.tf("show", 
			concat("Source saved to file: ", arg[1]));
		return;
 	break;
	case "torn":
		vspan = building_vspan();
		isTorn = 1;
		return;
	break;
	case "enter":
		set("cursor", 0); 
		return;
	break;
	case "raise":
		if (get("window")) raise();
		return;
	break;
	case "clone":
		id = id + 1;
		return clone(id);
	break;
	case "freeSelf":
		freeSelf();
		return;
	break;
	case "init":
		eventMask("-enterWindow -leaveWindow -keyPress -keyRelease");
	break;
	}
	usual();
