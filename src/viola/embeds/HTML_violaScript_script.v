/* HTML_violaScript_script.v
 * Handler for <SCRIPT TYPE="viola"> tag
 * Note: Since ACTION is SGML_LITTERAL, this script is not actually used.
 * ACTION parses its content directly to extract the viola script.
 * This file is kept for completeness in case we change the DTD.
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
	case 8:
		/* End of tag - pass script to parent if TYPE="viola" */
		if (scriptType == "viola" || scriptType == "VIOLA") {
			scriptCode = get("label");
			if (scriptCode != "" && scriptCode != "0") {
				send(parent(), "setScript", scriptCode);
			}
		}
		/* If TYPE is not viola (or not set), do nothing - ignore JS etc */
		return;
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
