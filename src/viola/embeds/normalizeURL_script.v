
/*
print("normalizeURL: ");
for (i=0; i < arg[]; i++) print("arg", i, " = ", arg[i], "\n");
print("\n");
*/
	switch (arg[0]) {
	case "normalizeURL":
		/* arg[1]	url
		 * arg[2]	context
		 */
		/* URL of this form "foo/bar/" ending with '/' 
		 * can lead to badness like "//muu" 
		 * What was this about??? sheesh.
		 */
/*		if (nthChar(arg[1], strlen(arg[1])-1) == '/')
			arg[1] = nthChar(arg[1], 0, strlen(arg[1])-2);
*/
		if (arg[] == 3) {
			/* set current document directory context.*/
			HTTPCurrentDocAddrSet(arg[2]);
			addrInfo = HTTPCurrentDocAddrParsed(arg[1], arg[2]);
		} else {
			addrInfo = HTTPCurrentDocAddrParsed(arg[1]);
		}

		if (nthChar(addrInfo[2], 0) == '/') {
			if (isBlank(addrInfo[1])) hostComponent = "";
			else hostComponent = concat("//", addrInfo[1]);
		} else {
			if (addrInfo[0] == "news") {
			   hostComponent = "";
			} else {
			  if (isBlank(addrInfo[1])) hostComponent = '/';
			  else hostComponent = concat("//", addrInfo[1], '/');
			}
		}
		normURL = concat(addrInfo[0], ":", hostComponent,
					addrInfo[2], addrInfo[3]);

		if (addrInfo[4] != "")
			normURL = concat(normURL, '#', addrInfo[4]);

		return normURL;
	break;
	}
	usual();
