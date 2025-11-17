
	switch (arg[0]) {
	case "entity":
		/* Add any pending label text first */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2;
			data[tokCount] = get("label");
			tokCount++;
		}

		/* Then add the entity token */
		entity_number = arg[1];
		if (entity_number == 51) {/*infin*/
			tok[tokCount] = 21; /*MINFO_INFIN*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 52) { /*integral*/
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 53) { /*sum*/
			tok[tokCount] = 20; /*MINFO_SUM*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 54) { /*pi*/
			tok[tokCount] = 22; /*MINFO_PI*/
			data[tokCount] = "";
			tokCount++;
		}

		/* Clear the label after processing */
		set("label", "");
		return;
	break;
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

		/* Send LBRACK token */
		send(parent(), "tok", 17); /* MINFO_LBRACK */

		/* Send all child tokens */
		for (i = 0; i < tokCount; i++) {
			send(parent(), "tok&data", tok[i], data[i]);
		}

		/* Send RBRACK token */
		send(parent(), "tok", 18); /* MINFO_RBRACK */
		
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

