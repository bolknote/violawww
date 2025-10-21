
	switch (arg[0]) {
	case "show":
		/* arg[1]	call back object
		 * arg[2]	HTMLAddress
		 * arg[3]	HTMLSource
		 */
		cloneID = cloneID + 1;
		new = clone(cloneID);
		send(new, "show_clone", arg[1], arg[2], arg[3]);
		send(new, "render");
		return;
	break;
	case "show_clone":
		caller = arg[1];
		HTMLAddress = arg[2];
		HTMLSource = arg[3];
		send(nthChild(0), "show", HTMLAddress);
		send(nthChild(1), "show", HTMLSource);
		return;
	break;
	case "apply":
		send(caller, "updateSrc", send(nthChild(1), "contentP"));
		return;
	break;
	case "store":
/*
		tmp = makeTempFile();
		saveFile(tmp, send(nthChild(1), "contentP"));
		print("ERROR: Sorry, source update feature doesn't yet exist. The changed document is saved in ", tmp, ".\n");
*/
		res.getLineEntry("show", 
			"Enter file name to save to document source to:", 
				"/tmp/out.html",
				self(), "gotOutputFileName");
		return;
	break;
	case "gotOutputFileName":
		if (saveFile(arg[1], send(nthChild(1), "contentP"))) {
			www.mesg.tf("show", 
				concatenate("Source saved to file: ",
					arg[1], "\n"));
		} else {
			www.mesg.tf("show", 
				concatenate("Failed to save source to file: ",
					arg[1], "\n"));
		}
		return;
 	break;
	case "dismiss":
		set("visible", 0);
		return;
	break;
	case "init":
		cloneID = 0;
	break;
	}
	usual();
