
	switch (arg[0]) {
	case "type":
		docURL = arg[1];
		if ((findPattern(docURL, ".pgp") > -1) || (findPattern(docURL, ".PGP") > -1)) {
			handler = "VWHandler_pgp";
		} else if ((findPattern(docURL, ".html") > -1) || (findPattern(docURL, ".HTML") > -1)) {
			handler = "VWHandler_html2";
		} else if ((findPattern(docURL, ".htm") > -1) || (findPattern(docURL, ".HTM") > -1)) {
			handler = "VWHandler_html2";
		} else if ((findPattern(docURL, ".hmmlb") > -1) || (findPattern(docURL, ".HMMLB") > -1)) {
			handler = "VWHandler_hmmlb";
		} else if ((findPattern(docURL, ".hmml") > -1) || (findPattern(docURL, ".HMML") > -1)) {
			handler = "VWHandler_hmml";
		} else if ((findPattern(docURL, ".au") > -1) || (findPattern(docURL, ".AU") > -1)) {
			handler = "VWHandler_au";
		} else if ((findPattern(docURL, ".gif") > -1) || (findPattern(docURL, ".GIF") > -1)) {
			handler = "VWHandler_gif";
		} else if ((findPattern(docURL, ".csh") > -1) || (findPattern(docURL, ".CSH") > -1)) {
			handler = "VWHandler_csh";
		} else if ((findPattern(docURL, ".ps") > -1) || (findPattern(docURL, ".PS") > -1)) {
			handler = "VWHandler_postscript";
		} else if ((findPattern(docURL, ".xbm") > -1) || (findPattern(docURL, ".XBM") > -1)) {
			handler = "VWHandler_xbm";
		} else if ((findPattern(docURL, ".xpm") > -1) || (findPattern(docURL, ".XPM") > -1)) {
			handler = "VWHandler_xpm";
		} else if ((findPattern(docURL, ".jpg") > -1) || (findPattern(docURL, ".JPG") > -1)) {
			handler = "VWHandler_extimg";
		} else if ((findPattern(docURL, ".jpeg") > -1) || (findPattern(docURL, ".JPEG") > -1)) {
			handler = "VWHandler_extimg";
		} else if ((findPattern(docURL, ".tif") > -1) || (findPattern(docURL, ".TIF") > -1)) {
			handler = "VWHandler_extimg";
		} else if ((findPattern(docURL, ".tiff") > -1) || (findPattern(docURL, ".TIFF") > -1)) {
			handler = "VWHandler_extimg";
		} else if ((findPattern(docURL, ".v") > -1) || (findPattern(docURL, ".V") > -1)) {
			handler = "VWHandler_vobjf";
		} else if ((findPattern(docURL, ".txt") > -1) || (findPattern(docURL, ".TXT") > -1)) {
			handler = "VWHandler_plaintext";
		} else if ((findPattern(docURL, ".text") > -1) || (findPattern(docURL, ".TEXT") > -1)) {
			handler = "VWHandler_plaintext";
		} else {
			handler = "VWHandler_html2";
		}
		return handler;
		break;
	}
	usual();
