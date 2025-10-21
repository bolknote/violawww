
	switch (arg[0]) {
	case "barScroll":
		return send(nthChild(0), arg[0], arg[1]);
	break;
	case "enable":
		enable = 1;
		barURL = arg[1];
		barRatio = arg[2];
		barMaxWidth = arg[3];
		parentWidth = arg[4];

		if (barMaxWidth != 0) {
			barWidth = barMaxWidth;
		} else {
			barWidth = float(parentWidth) * 
					float(barRatio) / 100.0;
		}
		set("width", barWidth);
		set("maxWidth", barWidth);
		set("visible", 1);
		send(nthChild(0), "show", barURL, barWidth);
		return;
	break;
	case "disable":
		enable = 0;
		set("visible", 0);
		set("y", 999);/*???? why won't this window go away??*/
		return;
	break;
	case "lbarEnabledP":
		return enable;
	break;
	case "resetWidthConstraint":
		parentWidth = arg[1];
		barWidth = float(parentWidth) * float(barRatio) / 100.0;
		set("width", 99);/*lame way to force a re config */
		set("maxWidth", barWidth);
		return;		
	break;
	}
	usual();
