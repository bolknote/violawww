
	switch (arg[0]) {
	case "suggest":
		if (suggest == 0) return;
		if (get("visible")) {
			if (arg[2] == "leave") {
				set("content", "");
				render();
				flush();
			} else {
				hint = send(arg[1], "hint");
				if (isBlank(hint) == 0) {
					set("content", hint);
					render();
					flush();
				}
			}
			isCleared = 0;
		}
		return;
	break;
	case "show_progress":
		/* arg[1]	percent
		 * arg[2]	bytes so far
		 */
		set("content", 
			concat("Retrieved ", arg[2], " bytes, ", arg[1], "%"));
		send("www.doc.tools.httpStat.icon", "stat", arg[1]);
		isCleared = 0;
		return;
	break;
	case "alert":
	case "flash":
	case "show":
	case "warn":
		set("content", arg[1]);
		render();
		flush();
		isCleared = 0;
		return;
	break;
	case "dialog_confirm":
		/* arg[1] message 
		 * ret: yes(1) or no(0)
		 */
		return wwwDialog_confirm("confirm", arg[1]);
	break;
	case "dialog_prompt_default":
		/* arg[1] message 
		 * arg[2] default
		 * ret: modification of the 'default' string.
		 */
		return wwwDialog_prompt_default("prompt", arg[1], arg[2]);
	break;
	case "dialog_prompt_password":
		/* arg[1] message 
		 * ret: password
		 */
		return wwwDialog_prompt_password("prompt", arg[1]);
	break;
	case "dialog_prompt_username_and_password":
		/* arg[1] message
		 * ret: username'\n'password
		 */
		return wwwDialog_prompt_username_and_password("prompt", arg[1]);
	break;
	case "clear":
		if (isCleared == 0) {
			set("content", "");
			render();
			flush();
			isCleared = 1;
		}
/*XXX many needless operations*/
		send("www.doc.tools.httpStat.icon", "clear");
		return;
	break;
	case "enter":
		set("cursor", 0);
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "The active hints/message text field....";
	break;
	case "keyPress":
		return;
	break;
	case "turnOffSuggest":
		suggest = 0;
		www.mesg.tf("warn", "Active help is now off.");
		return;
	break;
	case "toggleSuggest":
		if (suggest == 1) {
			suggest = 0;
			www.mesg.tf("warn", "Active help is now off.");
		} else {
			suggest = 1;
			www.mesg.tf("warn", "Active help is now on.");
		}
		return;
	break;
	case "init":
		usual();
/*		after(50000, "www.mesg.tf", "clear");*/
		suggest = 0;
		return;
	break;
	}
	usual();
