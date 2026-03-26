/* HTML_violaScript_script.v
 * Handler for <SCRIPT TYPE="viola"> tag
 *
 * CB_HTML_stag checks the TYPE attribute before the inside_ignore_element
 * guard: TYPE="viola" falls through to normal tag processing, reaching
 * this handler via the HTML_violaScript style mapping.  Plain <SCRIPT>
 * (no TYPE or non-viola TYPE) is suppressed before the style lookup.
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
