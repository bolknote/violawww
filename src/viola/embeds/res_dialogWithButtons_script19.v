
	switch (arg[0]) {
	case "show":
		set("content", arg[1]);
		return;
	break;
	case "config":
/*		print("----------------------------------GGG\n");
		for (i = 0; i < arg[]; i++) print(arg[i], ", ");
		print("\n");
*/
	break;
	case "cinfo":
		objectListSend("children", "info");
	break;
	case "done":
		send(parent(), arg[0]);
		set("children", "");
/*		after(1111, self(), "rip");*/
		return;
	break;
	case "rip":
/*		objectListSend("children", "freeSelf");*/
		set("children", "");
		return;
	break;
	case "adopt":
		/* arg[1] = <label>
		 * arg[2] = <action script>
		 */
/*
		print("----------------------------------\n");
		print("arg[1]>>>>", arg[1], "<<\n");
		print("arg[2]>>>>", arg[2], "<<\n");
*/
		cname = concat("foo", countChildren() + 1);
/*		print("cname>>>>", cname, "<<\n");
*/
		cscript = concat("if (arg[0] == \"buttonRelease\") {", 
					arg[2], 
					"\n send(parent(), \"done\");}\n",
					"usual();");
/*		print("cscript>>>>", cscript, "<<\n");
*/
		newobj = create("name", cname,
				"class", "txtButton",
				"parent", self(),
				"label", arg[1],
				"script", cscript,
				"width", "50",
				"height", "50",
				"font", "any",
				"gapH", "10");

		set("children", concat(get("children"), " ", newobj));
		return;
	break;
	}
	usual();
