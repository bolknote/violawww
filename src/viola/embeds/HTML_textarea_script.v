
/*
print(">>>> HTML_textarea.tf: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");print("...end\n");
*/
	switch (arg[0]) {
	case "make":
		/* arg[1]	defaultVal
		 */
		defaultVal = arg[1];
		if (defaultVal != 0) set("content", defaultVal);
		else set("content", "");

		eventMask("+enterWindow +leaveWindow");
		return;
	break;
	case 'R':
		/* arg[1]	y
		 * arg[2]	width
		 */
		clearWindow();
		if (style == 0) style = SGMLGetStyle("HTML", "TEXTAREA");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		set("width", arg[2] - x() - style[3]);
		set("content", get("content"));
		h = building_vspan();
		if (h < heightByRows) h = heightByRows;
		vspan += set("height", h) + style[1];
		render();
		return vspan;
	break;
	case "value":
		return get("content");
	break;
	case "reset":
		set("content", defaultVal);
		clearWindow();
		render();
		return;
	break;
	case "outputSGML":
		print("<TEXTAREA");
		if (tagID) print(" NAME=\"", tagID, "\"");
		if (type) print(" TYPE=\"", inputType, "\"");
		if (checked) print(" CHECKED");
		if (get("maxWidth") < 9999) 
			print(" MAXWIDTH=", get("maxWidth"));
		if (get("minWidth") < 9999) 
			print(" MINWIDTH=", get("minWidth"));
		print(">", get("content"), "<TEXTAREA>\n");
		return;
	break;
	}
	usual();
