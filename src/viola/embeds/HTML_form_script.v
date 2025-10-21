
	switch (arg[0]) {
	case "F":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		h = 0;
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */
		if (isBlank(get("label")) == 0) {
			if (style == 0) style = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			if (inPreP) txt = get("label");
			else txt = compressSpaces(get("label"));
			h = send(txtObj, "make", self(), txt,
				 style[3], 
				 get("width") - style[3] - style[2],
				 SGMLBuildDoc_span(), makeAnchor);
			makeAnchor = 0;
		}
		if (h == 0) return 1;
		set("height", h);
		return h;
	break;
	case "D":
		if (doneSetInPreP == 0) {
			inPreP = send(get("parent"), "inPreP");
			doneSetInPreP = 1;
		}
		h = get("height");
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			if (style == 0) style = SGMLGetStyle("HTML", "P");
			txtObj = HTML_txt("clone");
			objectListAppend_children(txtObj);
			if (inPreP) txt = get("label");
			else txt = compressSpaces(get("label"));
			h += send(txtObj, "make", self(), txt,
				 style[3], 
				 get("width") - style[3] - style[2],
				 h, makeAnchor);
			makeAnchor = 0;
		}
/*
		tagPtr = STG_tagPtr("FORM");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
/*		new = send("HTML_form.op", "clone", self());
		hh = send(new, "make", self(), get("width") - 4, h);
		objectListAppend_children(new);
		set("height", h + hh);
		return h + hh;
*/
		return h;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		if (style == 0) style = SGMLGetStyle("HTML", "SECTION");
		vspan = style[0];
		set("x", style[2]);
		set("y", arg[1] + vspan);
		set("width", arg[2] - x() - style[3]);
		n = countChildren();
		if (n) {
			xx = get("width") - 4;
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case 'r':
		if (style == 0) style = SGMLGetStyle("HTML", "SECTION");
		vspan = style[0];
		n = countChildren();
		if (n) {
			xx = get("width");
			for (i = 0; i < n; i++)
				vspan += send(nthChild(i), "R", vspan, xx);
		}
		set("height", vspan);
		vspan += style[1];
		return vspan;
	break;
	case "heightP":
		return get("height");
	break;
	case "widthP":
		return get("width");
	break;
	case "AI":
	case "noBullet":
		return;
	break;
	case "AA":
		switch (arg[1]) {
		case "ID":
			id = arg[2];
		break;
		case "MAXWIDTH":
			set("maxWidth", arg[2]);
		break;
		case "METHOD":
			method = arg[2];
		break;
		case "MINWIDTH":
			set("minWidth", arg[2]);
		break;
		case "ACTION":
			action = arg[2];
		break;
		case "BORDER":
			set("BDColor", get("FGColor"));
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
	case "regInputer":
		/* every input object within the form reports to the form,
		 * so that at submission time, the form can query the input
		 * objects for values.
		 */
		inputers[icount] = arg[1];
/*		val = send(inputers[icount], "value");*/
		icount++;
		return icount - 1;
	break;
	case "resetForm":
		for (i = 0; i < icount; i++) send(inputers[i], "reset");
		return;
	break;
	case "acceptForm":
		if (action != "") {
			if (findPattern(action, "mailto:") != -1) {
				/* EMail results
				 */
				url = subject = send(send(parent(),
							"findTop"),
							 "query_docURL");
				subject = url;
				address = nthChar(action, 7, 999);
				content = concat("Form URL : ", url, "\n\n",
						 "Action   : ", action, "\n");

				for (i = 0; i < icount; i++) {
					val = send(inputers[i], "value");
					if (val != 0) 
					  content = concat(mh, '\n', 
							   content, 
							   val, '\n');
				}
				
				tmpFile = makeTempFile();
				saveFile(tmpFile, content);

				wwwSecurity("mailFileContentTo,rmFile",
					    address, subject, tmpFile);
			} else {
				/* Compress results into one-liner. Ick!
				 */
				content = "";
				for (i = 0; i < icount; i++) {
					val = send(inputers[i], "value");
/*print("FORM VALUE >>>>>>>", val, "<<<\n");*/
					if (val != 0)
					  if(i == 0) {
						content = concat(content, 
						                 val);
					  } else {
						content = concat(content,
								 '&', val);
					  }
				}
				content = concat(content, "\n");

				if (method == "POST") {
/*print("FORM POST HREF N DATA >>>>>>>", concat(action, '?', content), "<<<\n");
*/
					send(send(parent(), "findTop"), 
						"post_href_n_data",
						action, content);
				} else {
/*print("FORM FOLLOW HREF >>>>>>>", concat(action, '?', content), "<<<\n");*/
					send(send(parent(), "findTop"), 
						"follow_href", 
						concat(action, '?', content));
				}
			}
		}
		return;
	break;
	case "searchAnchor":
		if (tagID == arg[1]) return self();
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				anchor = send(nthChild(i), 
						"searchAnchor", arg[1]);
				if (anchor != "") return anchor;
			}
		}
		return "";
	break;
	case "gotoAnchor":
		if (tagID == arg[1]) return get("y");
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++) {
				offset = send(nthChild(i), 
						"gotoAnchor", arg[1]);
				if (offset > 0) return offset + y();
			}
		}
		return 0;
	break;
	case "findTop":
		return send(parent(), "findTop");
	break;
	case "findForm":
		return self();
	break;
	case "reportMailHeader":
		mh = arg[1];
		return;
	break;
	case "radioReg":
		/* arg[1]	name of radio group
		 * arg[2]	radio (input) object to be added to group
		 */
		radioID[radioi] = arg[1];
		radioObj[radioi] = arg[2];
		radioi++;
		return;
	break;
	case "radioOnReq":
		/* arg[1]	radio group index
		 * arg[2]	the radio (input) object to be turned ON
		 */
		radioGroupName = arg[1];
		for (i = 0; i < radioi; i++)
			if (radioID[i] == radioGroupName)
				send(radioObj[i], "radioOff");
		send(arg[2], "radioOn");
		return;
	break;
	case "outputSGML":
		print("<FORM");
		if (id) print(" ID=\"", id, "\"");
		if (action) print(" ACTION=\"", action, "\"");
		if (method) print(" METHOD=\"", method, "\"");
		if (get("maxWidth") < 9999) 
				print(" MAXWIDTH=", get("maxWidth"));
		if (get("minWidth") < 9999) 
				print(" MINWIDTH=", get("minWidth"));
		print(">\n");
		n = countChildren();
		if (n > 0) {
			for (i = 0; i < n; i++)
				send(nthChild(i), "outputSGML");
		}
		print("</FORM>\n");
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
