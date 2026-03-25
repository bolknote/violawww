/* HTML_violaScript_script.v
 * Handler for <SCRIPT TYPE="viola"> tag
 *
 * Currently CB_HTML_stag ignores all SCRIPT tags at the C level
 * (inside_ignore_element guard), so this handler is not reached
 * in the HTML2 parsing path. It is kept so that if the SCRIPT
 * ignore guard is lifted for TYPE="viola", the object is ready.
 */

	switch (arg[0]) {
	case "AA":
		/* Handle attributes */
		switch (arg[1]) {
		case "TYPE":
			scriptType = arg[2];
		break;
		}
		return;
	break;
	case 'i':
		if (scriptType == "viola" || scriptType == "VIOLA") {
			scriptCode = get("label");
			if (scriptCode != "" && scriptCode != "0") {
				interpret(scriptCode);
			}
		}
		return "";
	break;
	case "D":
		return -1;
	break;
	case "config":
	case "AI":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		scriptType = "";
		scriptCode = "";
		return;
	break;
	}
	usual();
