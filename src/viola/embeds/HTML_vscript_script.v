/* HTML_vscript_script.v
 * Handler for <VSCRIPT> tag
 */

	switch (arg[0]) {
	case "D":
		return -1;
	break;
	case 'i':
		scriptCode = get("label");
		if (scriptCode != "" && scriptCode != "0") {
			interpret(scriptCode);
		}
		return "";
	break;
	case "AI":
	case "AA":
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return 0;
	break;
	case "init":
		usual();
		return;
	break;
	}
	usual();
