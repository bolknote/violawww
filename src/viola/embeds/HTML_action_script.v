/* HTML_action_script.v
 * Handler for <ACTION> tag
 * Extracts viola script from nested SCRIPT tag in label content
 * 
 * Expected format:
 *   <ACTION>
 *     <SCRIPT TYPE="viola">
 *       ... script code ...
 *     </SCRIPT>
 *   </ACTION>
 */

	switch (arg[0]) {
	case "D":
		/* For SGML_LITTERAL, content is added via D message */
		content = get("label");
		if (strlen(content) > 0) {
			/* Check if TYPE="viola" or TYPE=viola is present */
			typeIdx = findPattern(content, "viola");
			if (typeIdx > 0) {
				/* Find the first > after SCRIPT tag (marks end of opening tag) */
				gtIdx = findPattern(content, ">");
				if (gtIdx > 0) {
					scriptStart = gtIdx;
					
					/* Find </SCRIPT> end tag */
					endIdx = findPattern(content, "</SCRIPT>");
					if (endIdx <= 0) {
						endIdx = findPattern(content, "</script>");
					}
					if (endIdx <= 0) {
						endIdx = findPattern(content, "</S");
					}
					
					if (endIdx > 0) {
						/* endIdx is position of last char of </SCRIPT> (the >) */
						/* scriptStart is position of > after SCRIPT tag */
						/* Script content is from scriptStart+1 to endIdx-9 (before <) */
						scriptEndPos = endIdx - 9;
						if (scriptEndPos > scriptStart) {
							/* nthChar(str, startPos, endPos) - inclusive */
							_scriptCode = nthChar(content, scriptStart + 1, scriptEndPos);
							
							/* Send script to parent immediately */
							parnt = parent();
							if (parnt != "" && parnt != "0" && parnt != "(NULL)") {
								send(parnt, "setActionScript", _scriptCode);
							}
						}
					}
				}
			}
		}
		return -1;
	break;
	case "config":
		return;
	break;
	case "AI":
	case "AA":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		_scriptCode = "";
		return;
	break;
	case "R":
		return 0;
	break;
	}
	usual();
