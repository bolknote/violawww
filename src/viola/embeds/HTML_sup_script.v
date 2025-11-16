
	switch (arg[0]) {
	case "entity":
		/* Add any pending label text first */
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2;
			data[tokCount] = get("label");
			tokCount++;
			set("label", "");
		}
		
		/* Then handle math entities inside sup */
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
	case 'i':
		if (findPattern(parent(), "box") != -1 ||
		    findPattern(parent(), "math") != -1) {
			SGMLBuildDoc_setBuff(0);
			if (isBlank(get("label")) == 0) {
				tok[tokCount] = 2;
				data[tokCount] = get("label");
				tokCount++;
			}
			test3();
			send(parent(), "flush");
			send(parent(), "tok", 12/*S_SUP*/);
/*			for (i = 0; i < tokCount; i++) {
				print("sup_tok ", i, ":   type=", tok[i], 
					"  data={", data[i], "}\n");
			}
*/
			for (i = 0; i < tokCount; i++) {
				send(parent(), "tok&data", tok[i], data[i]);
			}
			send(parent(), "tok", 13/*E_SUP*/);
			tokCount = 0;
			return "";
		} else {
			pn = str(parent());
			tt = compressSpaces(get("label"));
			return concat("\\f(7)", tt, "\\f(1)");
		}
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
	case "over":
		tok[tokCount] = 4;
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "init":
		usual();
		SGMLBuildDoc_setColors();
		return;
	break;
	}
	usual();
