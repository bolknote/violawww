
.{Open URL (Uniform Resource Location)} {send("www", "openURL");}
.{Follow URL in Selection Buffer} {www("showHistoryDoc", trimEdge(getSelection()));}
.{\\}
.{Show Document Source} {send("www", "showSrc");}
.{Show Document Author Info} {www("authorContact");}
.{\\}
.{Software Version Info} {wwwAbout("visible", 1);}
.{\\}
.{Quit} {send(self(), "quit");}
