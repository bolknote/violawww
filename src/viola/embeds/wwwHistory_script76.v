
/*
	print("wwwHistory.tf: ");
	for (i = 0; i < arg[]; i++) print(arg[i], ", ");
	print("\n");
*/
	switch (arg[0]) {
	case "buttonRelease":
		if (isBlank(currentLine()) == 1) {
			bell();
		} else {
			deHighLight(index);
			previousDocIndx = index;
			/*index = lineRowOffset() + cursorRow();*/
			index = cursorRow();
			highLight(index);
			if (get("window")) render();
		}
		www("showButNoRecord", docAddr[index]);
	break;
	case "prev":
		if (index > 0) {
			deHighLight(index);
			previousDocIndx = index;
			index--;
			highLight(index);
			if (get("window")) render();
			return docAddr[index];
		} else {
			bell();
			return "";
		}
	break;
	case "peek_prev":
		if (index > 0) return docTitle[index - 1];
		else return "none";
	break;
	case "next":
		if (index < count - 1) {
			deHighLight(index);
			previousDocIndx = index;
			index++;
			highLight(index);
			if (get("window")) render();
			return docAddr[index];
		} else {
			bell();
			return "";
		}
	break;
	case "peek_next":
		if (index + 1 < count) return docTitle[index + 1];
		else return "none";
	break;
	case "toggle":
		if (previousDocIndx == -1) {
			return "";
		} else {
			deHighLight(index);
			temp = index;
			index = previousDocIndx;
			previousDocIndx = temp;
			highLight(index);
			if (get("window")) render();
			return docAddr[index];
		}
	break;
	case "peek_back":
		if (index > 0) return docTitle[index - 1];
		else return "none";
	break;
	case "add":
		deHighLight(index);
		previousDocIndx = index;
		index = count;
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
				send(victim, "visible", 0);
				send(victim, "freeSelf");
			}
		}
		tt = "";
		for (i = 0; i < count; i++)
			tt = concat(tt, docTitle[i], '\n');
		set("content", tt);
		highLight(index);
		if (get("window")) render();
		return;
	break;
	case "back":
		/* delete last line */
/*
print("count<=1", count <= 1, "\n");
p = count <= 1;
print("count<=1p ", p, "\n");
*/
		if (count <= 1) {
			bell();
		} else {
/*
print("NOW DESTROY index=", index, ": {", docAddr[index], "}<<<<<<<<<<<,\n");
*/
			www("destroyDoc", docAddr[index]);

			deHighLight(index);
			count--;
			if (index > -1) index--;
			previousDocIndx = index;
/*set("content", nthLine(get("content"), 0, count - 1));*/
/*GROSSY*/		tt = "";
			for (i = 0; i < count; i++)
				tt = concat(tt, docTitle[i], '\n');
			set("content", tt);
			highLight(index);
			if (get("window")) render();

		}
/*
print("NOW WANT index=",index, ": {", docAddr[index], "}\n");
print("count=", count, "\n");
print("HISTORY NOW:{", tt, "}\n");
*/
		return docAddr[index];
	break;
	case "config":
		/* this is necessary due to the bug where content can't be
		 * set until the object has been configured... and this is
		 * a problem because a document may be "added" here before
		 * the widgets are configured.
		 */
		usual();
		set("content", tt);
		return;
	break;
	case "historyQuery":
		/* arg[1]	cookie
		 */
		wwwHistory_report(arg[1], docTitle);
		return;
	break;
	case "query": /* query(n) -> text on line n */
		return nthLine(get("content"), arg[1]);
	break;
	case "clear":
		set("content", "");
	break;
	case "dump":
		for (i = 0; i < count; i++)
			print("[", i, "]	 docTitle={", docTitle[i], "}",
				"	docAddr={", docAddr[i], "}\n");
		return;
	break;
	case "enter":
	case "release":
	case "keyPress":
		return; 
	break;
	case "enter":
		set("cursor", 0); 
		return;
	break;
	case "init":
		usual();
		previousDocIndx = -1;
		index = -1;
		count = 0;
		killLatency = 10;
		return;
	break;
	}
	usual();
