/*
 * HTML_figure_script.v - FIGURE/FIG container element handler
 *
 * Handles the <FIGURE> (or <FIG>) tag which embeds images in HTML documents.
 * Supports multiple image formats: GIF, XBM, XPM, PostScript.
 *
 * Key attributes:
 *   TYPE   - Image format: "gif", "xbm", "xpm", "ps", or MIME types
 *   SRC    - URL to external image file
 *   ISMAP  - If present, enables server-side image map behavior
 *   LABEL  - Alternative identifier for the figure
 *
 * Child elements:
 *   <FIGDATA> - Inline image data (XBM/XPM C code format)
 *   <FIGA>    - Client-side image map hotspot regions
 *   <FIGCAP>  - Caption text for the figure
 *
 * Processing flow:
 *   1. Collects FIGA definitions via "addFigA" messages
 *   2. Creates appropriate image handler (HTML_giff, HTML_xbmf, etc.)
 *   3. Passes collected FIGA data to the image handler for hotspot creation
 */
	switch (arg[0]) {
	case "F":
		return -1;
	break;
	case "D":
/*		if (tagPtr == 0) tagPtr = STG_tagPtr("FIGURE");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (builtFig == 1) {
			h = SGMLBuildDoc_span() + style[1];
			set("height", h);
			builtFig = 0;
			return h;
		} else if (src != 0) {
			builtFig = 1;

			h = get("height");

			switch (bmType) {
			case "gif":
			case "image/gif":
				figTemplate = "HTML_giff";
			break;
			case "xbm":
			case "image/xbm":
				figTemplate = "HTML_xbmf";
			break;
			case "xpm":
			case "image/xpm":
				figTemplate = "HTML_xpmf";
			break;
			case "ps":
			case "application/postscript":
				figTemplate = "HTML_psf";
			break;
			}
			if (isBlank(figTemplate) == 1) {
				/* unknown type */
				return 0;
			} else {
				bitmapObj = send(figTemplate, "clone");
				w = width() - 10;
				h += send(bitmapObj, "make", self(), w, h,
					 src, delayP, delayWidth, delayHeight,
					 ismap);

				objectListPrepend("children", bitmapObj);

				/* oh heck */
				h = send(self(), 'R', get("y"), get("width"));
				for (i = 0; i < figaCount; i++) {
					send(bitmapObj, "addFigA", figaRef[i],
						figaX[i], figaY[i],
						figaW[i], figaH[i]);
				}
				if (style == 0)
					style = SGMLGetStyle("HTML", "FIGURE");
				return style[0] + h;
			}
		} else {
			if (isBlank(get("label")) == 1) return -1;

			builtFig = 1;
			h = SGMLBuildDoc_span();

			switch (bmType) {
			case "gif":
			case "image/gif":
			case "image/GIF":
				figTemplate = "HTML_gif";
			break;
			case "xbm":
			case "image/xbm":
				figTemplate = "HTML_xbm";
			break;
			case "xpm":
			case "image/xpm":
				figTemplate = "HTML_xpm";
			break;
			case "ps":
			case "application/postscript":
				figTemplate = "HTML_ps";
			break;
			default:
		print("HTML_figure.v: don't know what FIGURE TYPE is.\n");
			break;
			}

			if (isBlank(figTemplate) == 1) {
				/* unknown type */
				return 0;
			} else {
				bitmapObj = send(figTemplate, "clone");
				/* Use WIDTH/HEIGHT attributes if specified */
				w = delayWidth;
				if (w <= 0) w = width() - 10;
				h += send(bitmapObj, "make", self(), w, delayHeight,
					 get("label"), ismap);
				objectListPrepend("children", bitmapObj);

				/* oh heck */
				h = send(self(), 'R', get("y"), get("width"));

				for (i = 0; i < figaCount; i++) {
					send(bitmapObj, "addFigA", figaRef[i],
						figaX[i], figaY[i],
						figaW[i], figaH[i]);
				}
				if (style == 0)
					style = SGMLGetStyle("HTML", "FIGURE");
				return style[0] + h + style[1];
			}
		}
	break;
	case 'R': /* resize */
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	x (optional)
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "FIGURE");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - get("x") - style[3]);

		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "FIGURE");
		vspan = style[0];
		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), 'R', vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "data":
/*		SGMLBuildDoc_setBuff(-1);*/
		return compressSpaces(get("label"));
	break;
	case "AI":
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "TYPE":
			bmType = arg[2];
		break;
		case "ISMAP":
			ismap = 1;
		break;
		case "SRC":
			src = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		case "WIDTH":
			delayWidth = arg[2];
		break;
		case "HEIGHT":
			delayHeight = arg[2];
		break;
		case "MAYDELAY":
			delayP = arg[2];
		break;
		}
		return;
	break;
	case "inPreP":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		return inPreP;
	break;
	case "addFigA":
		figaRef[figaCount] = arg[1];
		figaX[figaCount] = arg[2];
		figaY[figaCount] = arg[3];
		figaW[figaCount] = arg[4];
		figaH[figaCount] = arg[5];
		++figaCount;
		return;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "clone":
		return clone(clone());
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
