
	switch (arg[0]) {
	case "input":
		ss = input();
		print(">>>> input={", ss, "}\n");
		cmd = nthWord(ss, 1);
		print(">>>> cmd={", cmd, "}\n");

		if (cmd == "SAID") {
			subCmd = nthWord(ss, 3);
			print(">>>> subCmd={", subCmd, "}\n");
			if (subCmd == "CEObj") {
				CEObjPath = nthWord(ss, 4, 999);
				print(">>>> CEObjPath={", CEObjPath, "}\n");
			} else if (subCmd == "CENewData") {
				CENewData = nthWord(ss, 4, 999);
				print(">>>> CENewData={", CENewData, "}\n");
				print(">>>> decoded CENewData={", 
					HTTPDecodeURL(CENewData), "}\n");
				send("www", "CE_change", 
					CEObjPath, HTTPDecodeURL(CENewData));
			} else if (subCmd == "CEObjLock") {
				CEObjPath = nthWord(ss, 4, 999);
				print(">>>> CEObjPath={", CEObjPath, "}\n");
				send("www", "CE_lock", 
					CEObjPath, HTTPDecodeURL(CENewData));
			} else if (subCmd == "CEObjUnLock") {
				CEObjPath = nthWord(ss, 4, 999);
				print(">>>> CEObjPath={", CEObjPath, "}\n");
				send("www", "CE_unlock", 
					CEObjPath, HTTPDecodeURL(CENewData));
			} else {
				print("www_com: unknown sub command", 
					subCmd, "\n");
			}
		}
		return;
	break;
	case "output_change":
		/* arg[1]	newObjPlacePath
		 * arg[2]	newData
		 */
		print(">>>>>>>>>>>>>>>>>>>>\n");
		out = concat("SAY CEObj: ", arg[1]);
		print(">>>> output'ing={", out, "}\n");
		output(out);
		out = concat("SAY CENewData: ", HTTPEncodeURL(arg[2]));
		print(">>>> output'ing={", out, "}\n");
		output(out);
		print(">>>>>>>>>>>>>>>>>>>>\n");
		return;
	break;
	case "output_lock":
		/* arg[1]	newObjPlacePath
		 */
		out = concat("SAY CEObjLock: ", arg[1]);
		print(">>>> output'ing={", out, "}\n");
		output(out);
		return;
	break;
	case "output_unlock":
		/* arg[1]	newObjPlacePath
		 */
		out = concat("SAY CEObjUnLock: ", arg[1]);
		print(">>>> output'ing={", out, "}\n");
		output(out);
		return;
	break;
	case "output":
		print(">>>> output'ing={", arg[1], "}\n");
		output(arg[1]);
		return;
	break;
	case "connect":
		print(">>>> connecting to host={", arg[1], "}\n");
		print(">>>> connecting to port={", arg[2], "}\n");
		set("host", arg[1]);
		set("port", arg[2]);
		set("outDelimStr", "\r\n");
		set("inDelimStr1", '\n');
		startClient();
		return;
	break;
	case "init":
		usual();
/*		send(self(), "connect", "localhost", 80);*/
		return;
	break;
	}
	usual();
