
	switch (arg[0]) {
	case "prev":
		if (index > 0) {
			index--;
			return docAddr[index];
		} else {
			bell();
			return "";
		}
	break;
	case "next":
		if (index < count - 1) {
			index++;
			return docAddr[index];
		} else {
			bell();
			return "";
		}
	break;
	case "add":
		index = count;
/*
print("HISTORY add: arg[1] {", arg[1], "}++++++++++++++++++++++++++\n");
print("             arg[2] {", arg[2], "}++++++++++++++++++++++++++\n");
*/
		if (isBlank(arg[1]) == 1) {
			docTitle[count] = "no title";
		} else {
			/* make sure we're storing string representation,
			 * rather than possibly object pointer which can
			 * get us into trouble if that object is destroyed
			 * and we reference it.
			 */
			docTitle[index] = str(arg[1]);
		}
		docAddr[index] = arg[2];
		count++;
		victimIdx = count - killLatency;
		if (victimIdx >= 0) {
			victim = docAddr[victimIdx];
			if (victim != arg[2]) {
/*print("KILLING idx=", victimIdx,"{", victim, "}\n");*/
				send(victim, "visible", 0);
				send(victim, "freeSelf");
			}
		}
		return;
	break;
	case "historyList_selectedItem":
		index = arg[1];
		return;
     	break;
	case "back":
		/* delete last line */
		if (count > 1) {
			mvw("destroyDoc", docAddr[index]);
			count--;
			/* move index only if at bottom of history list */
			if (index >= count) index--;
			return docAddr[index];
		} else {
			return docAddr[0];
		}
	break;
	case "dump":
		for (i = 0; i < count; i++)
			print("[", i, "]	 docTitle={", docTitle[i], "}",
				"	docAddr={", docAddr[i], "}\n");
		return;
	break;
	case "init":
		usual();
		index = -1;
		count = 0;
		killLatency = 4;
		return;
	break;
	}
	usual();
