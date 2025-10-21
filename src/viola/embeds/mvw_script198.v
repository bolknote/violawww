
	switch (arg[0]) {
	case "clear":
		if (isCleared == 0) {
			activeHelp();
			isCleared = 1;
		}
/*XXX many needless operations*/
		send("mvw.doc.tools.httpStat.icon", "clear");
		return;
	break;
	case "show":
	case "flash":
	case "suggest":
		isCleared = 0;
		return activeHelp(arg[1]);
	break;
	case "show_progress":
		/* arg[1]	percent
		 * arg[2]	bytes so far
		 */
		activeHelp(concat("Retrieved ", arg[2], " bytes, ", 
				  arg[1], "%"));
		send("mvw.doc.tools.httpStat.icon", "stat", arg[1]);
		isCleared = 0;
		return;
	break;
	case "alert":
	case "warn":
	case "error":
		isCleared = 0;
		sendToInterface("modalErrorDialog",
				0, /* may be on top of the wrong shell--
				    * now always go on main shell */
				arg[1]);
		return;
	break;
	}
	usual();
