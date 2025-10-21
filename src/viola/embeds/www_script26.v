
	switch (arg[0]) {
	case "quit":
		send("www", "quit");
		return;
	break;
	case "enter":
	case "leave":
		www.mesg.tf("suggest", get("name"), arg[0]);
		return;
	break;
	case "hint":
		return "Click to see some general project information.";
	break;
	}
	usual();
/*
Unreliable feature
.{\\}
.{Fonts}
..{Helvetica Small} {www("changeFonts", "useHelveticaSmallFonts");}
..{Helvetica Medium} {www("changeFonts", "useHelveticaMediumFonts");}
..{Helvetica Large} {www("changeFonts", "useHelveticaLargeFonts");}
..{\\}
..{Times Small} {www("changeFonts", "useTimesSmallFonts");}
..{Times Medium} {www("changeFonts", "useTimesMediumFonts");}
..{Times Large} {www("changeFonts", "useTimesLargeFonts");}
.{\\}
.{Expermental}
..{OUTPUT SGML} {send("www", "outputSGML");}
..{Edit On} {send("www", "editMode", 1);}
..{Edit Off} {send("www", "editMode", 0);}
..{LBar On 10} {send("www.doc.view", "lbarConfig", "on", 10);}
..{LBar On 20} {send("www.doc.view", "lbarConfig", "on", 20);}
..{LBar On 50} {send("www.doc.view", "lbarConfig", "on", 50);}
..{LBar Off} {send("www.doc.view", "lbarConfig", "off");}
.{Clone Page} {send("www", "tear");}
*/
