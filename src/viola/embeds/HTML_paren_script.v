
	switch (arg[0]) {
	case "tok&data":
		/* Receive tokens from children */
		tok[tokCount] = arg[1];
		data[tokCount] = arg[2];
		tokCount++;
		return;
	break;
	case "tok":
		/* Receive tokens from children */
		tok[tokCount] = arg[1];
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "flush":
		/* Transfer any pending data from global buffer to label */
		SGMLBuildDoc_setBuff(-1);
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		return;
	break;
	case "F":
		/* Transfer data from buffer to label and add to tokens NOW (before children) */
		SGMLBuildDoc_setBuff(-1);
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		return -1;
	break;
	case "D":
		/* Transfer any remaining data after children to label and add to tokens */
		SGMLBuildDoc_setBuff(0);
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}

		/* Send LPAREN token */
		send(parent(), "tok", 15); /* MINFO_LPAREN */

		/* Send all child tokens */
		for (i = 0; i < tokCount; i++) {
			send(parent(), "tok&data", tok[i], data[i]);
		}

		/* Send RPAREN token */
		send(parent(), "tok", 16); /* MINFO_RPAREN */
		
		tokCount = 0;
		return 0; /* destroy self */
	break;
	case "R":
		return 0;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "expose":
	case "render":
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();

