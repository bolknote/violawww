
	switch (arg[0]) {
	case "report":
		reason = arg[1];
/*print("############### FAILURE REPORT ##############\n",
reason, "\n#############################################\n");
*/
		return;
	break;
	case "reportP":
		return reason;
	break;
	case "make":
		set("parent", arg[1]);	
		set("name", arg[2]);
		set("width", arg[3]);
		set("height", arg[4]);

		/* reason of failure assume to be previously reported by
		 * the failure detection point
		 */
		set("content", VWHandler_fail("reportP"));
		reason = "Cause of failure unreported."; /* reset */

		return self();
	break;
	case "clone":
		return clone(arg[1]);
	break;
	case 'T':
		/* arg[1] = y
		 * arg[2] = width
		 */
		h = get("height");
		parentHeight = send(parent(), "heightP");
		heightDiff = h - parentHeight;
		if (heightDiff > 0) {
			heightRatio =  float(heightDiff) / -100.0;
		} else {
			heightRatio = 0;
			h = parentHeight;
			set("height", h);
		}
		prevWidth = arg[2];
		prevHeight = parentHeight;
		return h;
	break;
	case "nameAndURL":
		docName = arg[1];
		docURL = arg[2];
		return;		
	break;
	case "queryAddress":
		return docURL;
	break;
	case "queryTitle":
		return "Access Failure";
	break;
	case "queryIsIndex":
		return 0;
	break;
	case "historyRecord":
		wwwHistory("add", docName, docURL);
		return;
	break;
	case "raise":
		raise();
		return;
	break;
	case "show":
		set("visible", 1);
		raise();
		return;
	break;
	case "display":
		/* arg[1]	width (of viewer window)
		 * arg[2]	height (of viewer window)
		 */
		raise();
		if (arg[1] != prevWidth) {
			/* need to re-format */
			send(self(), "resize", arg[1], arg[2]);
		} else if (arg[2] != prevHeight) {
			/* just adjust window height */
			send(self(), "resize", arg[1], arg[2]);
		}
		return;
	break;
	case "findTop":
		return self();
	break;
	case "yP":
		return y();
	break;
	case "y":
		return set("y", arg[1]);
	break;
	case "heightP":
	case "vspan":
		return height();
	break;
	case "VW_relay":
		relay_obj[relayIdx] = arg[1];
		relay_event[relayIdx] = arg[2];
	 	relayIdx= relayIdx + 1;
		return 1;
	break;
	case "VW_event":
		event = arg[1];
		for (i = 0; i < relayIdx; i = i + 1) {
			if (relay_event[i] = event) {
				send(relay_obj[i], event);
			}
		}
		return;
	break;
	}
	usual();
