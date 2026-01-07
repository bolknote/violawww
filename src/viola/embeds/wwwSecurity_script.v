
	/* Security wall for file operations */

	switch (arg[0]) {
	case "rmTmpFile":
		/* Safely delete a temporary file
		 * Security: validates path is in temp directory and contains no traversal
		 */
		path = arg[1];
		
		/* Check for blank */
		if (isBlank(path) == 1) return 0;
		
		/* Check for path traversal */
		if (findPattern(path, "..") != -1) {
			print("Security: path traversal blocked\n");
			return 0;
		}
		
		/* Check for shell metacharacters */
		if (findPattern(path, ";") != -1) return 0;
		if (findPattern(path, "|") != -1) return 0;
		if (findPattern(path, "&") != -1) return 0;
		if (findPattern(path, "`") != -1) return 0;
		if (findPattern(path, "$") != -1) return 0;
		if (findPattern(path, "(") != -1) return 0;
		if (findPattern(path, ")") != -1) return 0;
		if (findPattern(path, "<") != -1) return 0;
		if (findPattern(path, ">") != -1) return 0;
		
		/* Must start with /tmp/ or /var/tmp/ */
		if (nthChar(path, 0, 4) == "/tmp/") {
			deleteFile(path);
			return 1;
		}
		if (nthChar(path, 0, 8) == "/var/tmp/") {
			deleteFile(path);
			return 1;
		}
		
		/* Check TMPDIR */
		tmpDir = environVar("TMPDIR");
		if (isBlank(tmpDir) == 1) return 0;
		
		if (nthChar(tmpDir, strlen(tmpDir) - 1) != '/') {
			tmpDir = concat(tmpDir, "/");
		}
		
		if (nthChar(path, 0, strlen(tmpDir) - 1) == tmpDir) {
			deleteFile(path);
			return 1;
		}
		
		return 0;
	break;
	
	case "getDocAndMoveItToSpecifiedPlace":
		/* Download document and save to specified location
		 * DISABLED: shell injection risk, needs C implementation
		 */
		print("Security: getDocAndMoveItToSpecifiedPlace is disabled\n");
		return 0;
	break;
	
	case "mailFileContentTo,rmFile":
		/* Send file contents via email and delete the file
		 * DISABLED: shell injection risk, needs C implementation
		 */
		print("Security: mailFileContentTo,rmFile is disabled\n");
		return 0;
	break;
	}
	usual();
