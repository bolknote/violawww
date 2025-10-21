
	switch (arg[0]) {
	case "type":
		docURL = arg[1];
		if (findPattern(docURL, ".pgp") > -1) {
			handler = "VWHandler_pgp";
		} else if (findPattern(docURL, ".html") > -1) {
/*			handler = "VWHandler_html";*/
			handler = "VWHandler_html2";
		} else if (findPattern(docURL, ".hmmlb") > -1) {
			handler = "VWHandler_hmmlb";
		} else if (findPattern(docURL, ".hmml") > -1) {
			handler = "VWHandler_hmml";
		} else if (findPattern(docURL, ".au") > -1) {
			handler = "VWHandler_au";
		} else if (findPattern(docURL, ".gif") > -1) {
			handler = "VWHandler_gif";
		} else if (findPattern(docURL, ".csh") > -1) {
			handler = "VWHandler_csh";
		} else if (findPattern(docURL, ".ps") > -1) {
			handler = "VWHandler_postscript";
		} else if (findPattern(docURL, ".xbm") > -1) {
			handler = "VWHandler_xbm";
		} else if (findPattern(docURL, ".xpm") > -1) {
			handler = "VWHandler_xpm";
		} else if (findPattern(docURL, ".v") > -1) {
			handler = "VWHandler_vobjf";

/*needs better recognition!!!! 
		} else if (findPattern(docURL, "index") > -1) {
			handler = "waisDB";
*/
		} else if (findPattern(docURL, ".txt") > -1) {
			handler = "VWHandler_plaintext";
		} else if (findPattern(docURL, ".text") > -1) {
			handler = "VWHandler_plaintext";
		} else {
/*			print("WARNING: format unknown: ",
				docURL, ". Treating as HTML.\n");
			handler = "VWHandler_html";
*/
			handler = "VWHandler_html2";
		}
		return handler;
		break;
	}
	usual();
