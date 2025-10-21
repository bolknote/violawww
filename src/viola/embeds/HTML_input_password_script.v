
	switch (arg[0]) {
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 * arg[3]	height
		 */
		set("width", arg[2] - 2);
		return get("height") + 2;
	break;
	case "make":
		/* arg[1]	parent
		 * arg[2]	defaultValue
		 * arg[3]	width
		 * arg[4]	height
		 * ...
		 * arg[7]	disabled
		 */
/*		tagPtr = STG_tagPtr("INPUT");
		if (tagPtr) {
			i = STG_attr(tagPtr, "BGColor");
			if (i) set("BGColor", i);
			i = STG_attr(tagPtr, "FGColor");
			if (i) set("FGColor", i);
			i = STG_attr(tagPtr, "BDColor");
			if (i) set("BDColor", i);
		}
*/
		if (arg[6]) disabled = 1;

		set("parent", arg[1]);
		defaultVal = arg[2];
		set("content", defaultVal);
		set("width", arg[3]);
		set("height", arg[4]);
		return get("height") + 2;
	break;
	case "enter":
		if (disabled) return;
	break;
	case "keyPress":
		if (disabled) {
			bell();
			send("www.mesg.tf", "suggest", 
				"This field has been disabled\n");
			return;
		} else {
			c = key();

			if (c >= ' ' &&  c <= '~') {
				passwd[sl] = c;
				sl++;
			} else {
				if (c == '\r' || c == '\n') {
					return;
				} else if (c == '\8') {
				  /* 8==Backspace. surely not the way?*/
					if (sl > 0) sl--;
				}
			}
			send(self(), "setScreen");
		}
		return;
	break;
	case "setScreen":
		if (sl == 0) set("content", "");
		else set("content", 
			nthChar("****************************************",
				1, sl));
		render();
		return;
	break;
	case "leave":
		if (checkChars) send(self(), "checkChars");
	break;
	case "value":
		passwdStr = "";
		for (i = 0; i < sl; i++)
			passwdStr = concat(passwdStr, passwd[i]);
		return passwdStr;
	break;
	case "reset":
		set("content", defaultVal);
		clearWindow();
		render();
		return;
	break;
	case "clone":
		return clone(cloneID());
	break;
	}
	usual();
