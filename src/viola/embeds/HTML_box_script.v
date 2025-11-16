

	switch (arg[0]) {
case "clone":
		return code_HTML_txt(arg);
break;
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
		} else if (entity_number == 65) { /*pi*/
			tok[tokCount] = 22; /*MINFO_PI*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 68) { /*sigma*/
			tok[tokCount] = 20; /*MINFO_SUM*/
			data[tokCount] = "";
			tokCount++;
		}
		return;
	break;
	case "tok&data":
		/* arg[1]	token
		 * arg[2]	data
		 */
		tok[tokCount] = arg[1];
		data[tokCount] = arg[2];
		tokCount++;
		return;
	break;
	case "data":
		/* arg[1]	data
		 */
		tok[tokCount] = 2;
		data[tokCount] = arg[1];
		tokCount++;
		return;
	break;
	case "tok":
		/* arg[1]	token type
		 */
		tok[tokCount] = arg[1];
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "flush":
		/* Flush any pending label to tok buffer before sub/sup processing */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		return;
	break;
	case "over":
		tok[tokCount] = 4;
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "flush":
		/* First, transfer any pending data from global buffer to label */
		SGMLBuildDoc_setBuff(-1);
		/* Then flush label to tok buffer before sub/sup processing */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2; /* MINFO_DATA */
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		return;
	break;
	case "F":
		/* Just transfer data from buffer to label, don't add to tokens yet */
		SGMLBuildDoc_setBuff(-1);
		return -1;
	break;
	case "D":
		SGMLBuildDoc_setBuff(0);
		/* Add label at the BEGINNING of token array if present */
		if (isBlank(get("label")) == 0) {
			/* Shift existing tokens to make room */
			for (i = tokCount; i > 0; i--) {
				tok[i] = tok[i-1];
				data[i] = data[i-1];
			}
			/* Insert label at position 0 */
			tok[0] = 2; /* MINFO_DATA */
			data[0] = get("label");
			tokCount++;
			set("label", "");
		}

		send(parent(), "tok", 5/*BOX_BEGIN*/);

		for (i = 0; i < tokCount; i++) {
			send(parent(), "tok&data", tok[i], data[i]);
		}
		send(parent(), "tok", 6/*BOX_END*/);
		tokCount = 0;

		return 0;/*destroy self*/
	break;
	case "R":
		return 0;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
