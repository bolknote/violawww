
	switch (arg[0]) {
	case "D":
		docURL = violaSrc;

		localFile = HTTPGet(docURL);

		addrInfo = HTTPCurrentDocAddrParsed(localFile);

		if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];
		else path = concat('/', addrInfo[2]);
		objFileName = addrInfo[3];

		addrInfo = HTTPCurrentDocAddrParsed(docURL);
		objName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);

		stat = loadObjFile(path, objFileName);

		send("wwwSecurity", "rmTmpFile", localFile);

		if (stat <= 0) {
			print("failed to load obj file {", objFileName,
				"} in {", path, "}\n");

			new = send("HTML_fail", "clone");
			set("children", new);
			vspan = send(new, "make", self(), get("width"),
				     concat("Insert failed here: ", docURL));
			return vspan;
		}

		send(objName, "init"); /* make new object(s) */

		set("children", objName);
		tweak(objName, concat("set(\"parent\", \"", self(), "\");"));

		/* kludge */
		after(1, objName, "configSelf");
/*
		after(1, self(), "config", x(), y(), width(), height()+2);
		deepObjectListSend("children", "configSelf");
*/
		vspan = tweak(nthChild(0), "height();") + 2;
		return vspan;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "VOBJF");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);
		vspan = tweak(nthChild(0), "height();") + 2;
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "VOBJF");
		set("width", get("width") - style[3]);
		vspan = tweak(nthChild(0), "height();") + 2;
		return vspan;
	break;
	case "AA":
		switch (arg[1]) {
		case "HREF":
			violaSrc = arg[2];
		break;
		case "ARG":
			arg = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		}
		return;
	break;
	case "AI":
		return;
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "gotoAnchor":
		return "";
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
