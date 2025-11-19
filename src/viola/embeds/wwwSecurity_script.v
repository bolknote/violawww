
	/* this security wall is terribly lay back now */

	switch (arg[0]) {
	case "rmTmpFile":
		/* need to check that the file is indeed a temporary
		 * file created by viola...
		 */
		if (nthChar(arg[1], 0, 4) == "/tmp/" || nthChar(arg[1], 0, 8) == "/var/tmp/") {
			deleteFile(arg[1]);
			return 1;
		}

		tmpDir = environVar("TMPDIR");
		if (isBlank(tmpDir) == 1) return 0;
		
		if (nthChar(tmpDir, strlen(tmpDir) - 1) != '/') {
			tmpDir = concat(tmpDir, "/");
		}

		pos = findPattern(arg[1], tmpDir);
		last = strlen(tmpDir) - 1;

		if (pos != -1 && pos == last) {
			deleteFile(arg[1]);
			return 1;
		}
		return 0;
	break;
	case "getDocAndMoveItToSpecifiedPlace":
		/* this is call by HTML__doc. Need a way to autheticate
		 * that it's indeed HTML__doc that's calling ...
		 */
		/* arg[1]	docURL
		 * arg[2]	destination
		 */
		if (access(arg[2])) {
			/* should query to confirm */
			print("Warning: overwriting ", arg[2], "...\n");
		}
		dumpFile = HTTPGet(arg[1]);
		system(concat("mv ", dumpFile, " ", arg[2]));
		return 1;
	break;
	case "mailFileContentTo,rmFile":
		/* arg[1]	email address
		 * arg[2]	subject line
		 * arg[3]	tmpFileName
		 */
		cmd = concat("mail -s \"", arg[2],
				"\" ", arg[1], " < ", arg[3]);
		/*print("CMD >>", cmd, "<<\n");*/
		system(cmd);
		deleteFile(tmpFile);
	break;
	}
	usual();
