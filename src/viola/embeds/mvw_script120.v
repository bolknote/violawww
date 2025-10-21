
	switch (arg[0]) {
	case "show":
		if (isBlank(arg[1])) {
/*			set("content", "<No Title>");*/
			set("content", "");
		} else {
			if (textWidth(6/*bold_largest*/, arg[1])+10 
			    < width()) {
				/*set("font", "bold_largest");*/
				set("content", concat("\\f(6)", arg[1]));
			} else {
				/*set("font", "bold");*/
				set("content", concat("\\f(5)", arg[1]));
			}
		}
		render();
		return;
	break;
	case "torn":
		return;
	break;
	}
	usual();
