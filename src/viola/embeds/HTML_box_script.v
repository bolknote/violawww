

print("HTML_box: self=", self(), ": ");
for (i=0; i<arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("^^^^^^^end\n");

	switch (arg[0]) {
	case "entity":
print("ENTITY FLUSH MATH label>>>>>", get("label"), "<<<\n");
		if (isBlank(get("label"))) return 0;
		tok[tokCount] = 2;
		data[tokCount] = get("label");
		tokCount++;

		entity_number = arg[1];
		if (entity_number == 50) {/*infin*/
		} else if (entity_number == 51) { /*integral*/
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/
			data[tokCount] = "";
			tokCount++;
		} else if (entity_number == 65) { /*sigma*/
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
	case "over":
		tok[tokCount] = 4;
		data[tokCount] = "";
		tokCount++;
		return;
	break;
	case "F":
print("F BOX--- label-{", get("label"), "}\n");
		if (isBlank(get("label"))) return -1;
		tok[tokCount] = 2;
		data[tokCount] = get("label");
		tokCount++;
		return -1;
	break;
	case "D":
		SGMLBuildDoc_setBuff(0);
print("D BOX--- label-{", get("label"), "}\n");
		if (isBlank(get("label")) == 0) {
			tok[tokCount] = 2;
			data[tokCount] = get("label");
			tokCount++;
		}

		send(parent(), "tok", 5/*BOX_BEGIN*/);

		for (i = 0; i < tokCount; i++) {
			print("XXX box_tok ", i, ":   type=", tok[i], 
				"  data={", data[i], "}\n");
		}

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
