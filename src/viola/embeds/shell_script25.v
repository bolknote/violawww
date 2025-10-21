
	switch (arg[0]) {
	case "tool":
		tool(arg[1]);
		shell.mesg("show", concatenate("current tool: ", arg[1]));
	break;
	}
	usual();
