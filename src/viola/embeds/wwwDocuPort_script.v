
	switch (arg[0]) {
	case "listen":
		port = arg[1];
		path = arg[2];
		return 0;
	break;
	case "init":
		initialize();
                set("inDelimStr1", "\r");
                set("inDelimStr2", "\n");
/*                startClient();*/
		return;
	break;
	case "input":
		in = input();
		if (isBlank(in)) { 
			print("www.listen: bad input = ``", in, "''\n");
		} else {
			docID = nthChar(in, 0, strlen(in)); 
			print("www.listen: input = ``", docID, "''\n");
			www("show", docID);
		}
		return;
	break;
	}
	usual();
