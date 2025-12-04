
	switch (arg[0]) {
	case 'i':
		switch (rel) {
		case "made":
			send(send(parent(), "findTop"), "reportAuthor", href);
		break;
		case "style":
			STG_clean(0/*useless arg*/);
			localFile = HTTPGet(href);
			loadSTG(localFile);
			/* Reset link colors to default (black) then apply from STG */
			resetLinkColors();
			tagPtr = STG_tagPtr("A");
			if (tagPtr) {
				fc = STG_attr(tagPtr, "FGColor");
				if (fc) setLinkColor(fc);
				tc = STG_attr(tagPtr, "traversedForegroundColor");
				if (tc) setLinkVisitedColor(tc);
			}
			oarg = 0;
			oargc = 0;
		break;
		case "sidebar":
			/* Rule to be... can't do because of parser bug
			 * if 'maxWidth' is given, that's used.
			 * if not then 'ratio' is used, if it is given.
			barRatio = 0;
			barMaxWidth = 0;

/**** a parser bug prevents multiple instances of the same attributes!!!

			flag = 0;
			for (i = 0; i < oargc; i++) {
				if (flag == 0) flag = oarg[i];
				else {
					if (flag == "maxWidth") 
						barMaxWidth = oarg[i];
					else if (flag == "ratio") 
						barRatio = oarg[i];
					flag = 0;
				}
			}
*/
			barRatio = oarg[0];
/*
print("Bar ratio=", barRatio, "\n");
print("Bar maxWidth=", barMaxWidth, "\n");
*/
			send(send(parent(), "findTop"), "linkSideBar", 
				href, barRatio, barMaxWidth);
			oarg = 0;
			oargc = 0;
		break;
		case "tool":
			localFile = HTTPGet(href);
			addrInfo = HTTPCurrentDocAddrParsed(localFile);

			if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];
			else path = concat('/', addrInfo[2]);
			objFileName = addrInfo[3];

			addrInfo = HTTPCurrentDocAddrParsed(href);
			objName = nthChar(addrInfo[3], 0, 
					strlen(addrInfo[3]) - 3);
			if (exist(objName)) {
				send(send(parent(), "findTop"), "addTool", 
					objName);
				return "";
			}

			stat = loadObjFile(path, objFileName);

			send("wwwSecurity", "rmTmpFile", localFile);

			if (stat <= 0) {
				print("failed to load obj file {", objFileName,
					"} in {", path, "}\n");
			}
			securityMode(1); 
			send(objName, "init"); /* make new object(s) */
			securityMode(0);

			send(send(parent(), "findTop"), "addTool", objName,
				oarg, oargc);
			oarg = 0;
			oargc = 0;
		break;
		case "vobj":
			localFile = HTTPGet(href);
			addrInfo = HTTPCurrentDocAddrParsed(localFile);

			if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];
			else path = concat('/', addrInfo[2]);
			objFileName = addrInfo[3];

			addrInfo = HTTPCurrentDocAddrParsed(href);
			objName = nthChar(addrInfo[3], 0, 
					strlen(addrInfo[3]) - 3);

			stat = loadObjFile(path, objFileName);

			send("wwwSecurity", "rmTmpFile", localFile);

			if (stat <= 0) {
				print("failed to load obj file {", objFileName,
					"} in {", path, "}\n");
			}
			securityMode(1); 
			send(objName, "init"); /* make new object(s) */
			securityMode(0);
/*
print("HTML_LINK load vobj=>>>>>>", objName, "<<\n");
			for(i=0; i<oargc; i++) {
print("HTML_LINK oarg[", i, "]= >", oarg[i], "<\n");
			}
*/
			if (oarg[] >= 1)
				h = send(objName, "make", self(), oarg[0]);

			after(1, objName, "configSelf");
			oarg = 0;
			oargc = 0;
			rel = 0;
			href = 0;
			t = concat("\\o(", objName, ")");
			return t;
		break;
		}
		rel = 0;
		href = 0;
		return "";
	break;
	case "config":
	case "R":
		return 0;
	break;
	case "AI":
	case "noBullet":
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ARG":
			oarg[oargc++] = arg[2];

/*It appears the HTML parser won't handle multiple same attrs.
print("HTML_LINK ADDING oarg[", oargc - 1, "]= >", oarg[oargc - 1], "<\n");
*/
		break;
		case "REL":
			rel = arg[2];
		break;
		case "HREF":
			href = arg[2];
		break;
		}
		return;
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
