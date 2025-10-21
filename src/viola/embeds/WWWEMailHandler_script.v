
	switch (arg[0]) {
	case "connect":
		/* forms:
		 *	telnetaddress=	telnet://[user@]hostport
		 *	hostport=	host[:port]
		 *
		 * returns a shell command
		 */
		tt = nthChar(arg[1], 9, 999);

		/* to get rid of the mysterious '/' at end of string??? */
		if (nthChar(tt, strlen(tt) - 1) == '/') {
			tt = nthChar(tt, 0, strlen(tt) - 2);
		}

		ati = findPattern(tt, "@");
		if (ati != -1) {
			/* form:	telnet://user@host
			 */
			user = nthChar(tt, 0, ati - 1);
			host = nthChar(tt, ati + 1, 999);

			cmd = concat("xterm -e 'rlogin ", 
					host, " -l ", user, "' &");
			return cmd;
		}

		ati = findPattern(tt, ":");
		if (ati != -1) {
			/* form:	telnet://host:port
			 */
			host = nthChar(tt, 0, ati - 1);
			port = nthChar(tt, ati + 1, 999);
			cmd = concat("xterm -e 'telnet ", 
					host, " ", port, "' &");
			return cmd;

		} else {
			/* form:	telnet://host
			 */
			cmd = concat("xterm -e 'telnet ", tt, "' &");
			return cmd;
		}
	break;
	}
	usual();
