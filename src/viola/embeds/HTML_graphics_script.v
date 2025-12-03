
	switch (arg[0]) {
	case "addChild":
		/* Child primitive registering itself - store in script variable */
		childObj = arg[1];
		if (gfxChildCount == 0) {
			gfxChildren = childObj;
		} else {
			gfxChildren = concat(gfxChildren, " ", childObj);
		}
		gfxChildCount = gfxChildCount + 1;
		print("[GRAPHICS] ", self(), " addChild: ", childObj, " count=", gfxChildCount, "\n");
		return;
	break;
	case "setBGColor":
		/* Set background color from BGCOLOR child tag */
		print("[GRAPHICS] setBGColor: ", arg[1], "\n");
		set("BGColor", arg[1]);
		return;
	break;
	case "expose":
		/* Container draws all children using own window */
		childList = gfxChildren;
		print("[GRAPHICS] expose: ", self(), " gfxChildCount=", gfxChildCount, " childList='", childList, "'\n");
		if (gfxChildCount > 0 && isBlank(childList) == 0) {
			/* Iterate through all children (space-separated list) */
			numChildren = 1;
			/* Count spaces to get number of children */
			for (idx = 0; idx < strlen(childList); idx++) {
				if (nthChar(childList, idx) == " ") {
					numChildren = numChildren + 1;
				}
			}
			
			/* Draw each child */
			startIdx = 0;
			for (childNum = 0; childNum < numChildren; childNum++) {
				/* Find next space or end */
				endIdx = startIdx;
				while (endIdx < strlen(childList) && nthChar(childList, endIdx) != " ") {
					endIdx = endIdx + 1;
				}
				
				/* Extract child name */
				if (endIdx > startIdx) {
					childName = nthChar(childList, startIdx, endIdx - 1);
					
					if (exist(childName) == 1) {
						/* Query child for shape type and color */
						shapeType = send(childName, "getShapeType");
						shapeFG = send(childName, "getFG");
						print("[GRAPHICS] drawing: ", childName, " type=", shapeType, " fg=", shapeFG, "\n");
						
						/* Set color */
						if (isBlank(shapeFG) == 0) {
							set("FGColor", shapeFG);
						}
						
						if (shapeType == "polygon") {
							/* Polygon uses points, not X/Y/W/H */
							numPoints = send(childName, "getPoints");
							print("[GRAPHICS] polygon numPoints=", numPoints, "\n");
							if (numPoints >= 2) {
								for (pi = 0; pi < numPoints - 1; pi++) {
									px1 = send(childName, "getPointX", pi);
									py1 = send(childName, "getPointY", pi);
									px2 = send(childName, "getPointX", pi + 1);
									py2 = send(childName, "getPointY", pi + 1);
									print("[GRAPHICS] polygon line: ", px1, ",", py1, " to ", px2, ",", py2, "\n");
									drawLine(px1, py1, px2, py2);
								}
								/* Close polygon */
								if (numPoints >= 3) {
									px1 = send(childName, "getPointX", numPoints - 1);
									py1 = send(childName, "getPointY", numPoints - 1);
									px2 = send(childName, "getPointX", 0);
									py2 = send(childName, "getPointY", 0);
									print("[GRAPHICS] polygon close: ", px1, ",", py1, " to ", px2, ",", py2, "\n");
									drawLine(px1, py1, px2, py2);
								}
							}
						} else {
							/* Other shapes use X/Y/W/H */
							shapeX = send(childName, "getX");
							shapeY = send(childName, "getY");
							shapeW = send(childName, "getW");
							shapeH = send(childName, "getH");
							print("[GRAPHICS] shape pos=", shapeX, ",", shapeY, " size=", shapeW, "x", shapeH, "\n");
							
							if (shapeType == "rect") {
								drawFillRect(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
							}
							if (shapeType == "circle") {
								drawFillOval(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
							}
							if (shapeType == "oval") {
								drawFillOval(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
							}
							if (shapeType == "line") {
								drawLine(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
							}
						}
					}
				}
				startIdx = endIdx + 1;
			}
		}
		return;
	break;
	case "D":
		/* Done building - nothing special needed */
		print("[GRAPHICS] D: done building\n");
		return 1;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
		print("[GRAPHICS] R: y=", arg[1], " width=", arg[2], "\n");
		if (style == 0) style = SGMLGetStyle("HTML", "GRAPHICS");
		vspan = style[0];
		set("y", arg[1] + vspan);
		set("x", style[2]);
		
		/* Use WIDTH/HEIGHT attributes if set, otherwise use available width */
		if (gWidth > 0) {
			set("width", gWidth);
		} else {
			set("width", arg[2] - get("x") - style[3]);
		}
		if (gHeight > 0) {
			set("height", gHeight);
		} else {
			set("height", 100); /* default height */
		}
		
		vspan += get("height") + style[1];
		print("[GRAPHICS] R: final size ", width(), "x", height(), " vspan=", vspan, "\n");
		return vspan;
	break;
	case "AA":
		print("[GRAPHICS] AA: ", arg[1], "=", arg[2], "\n");
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
		break;
		case "WIDTH":
			gWidth = int(arg[2]);
		break;
		case "HEIGHT":
			gHeight = int(arg[2]);
		break;
		}
		return;
	break;
	case "AI":
		/* Implied attribute - ignore */
		return;
	break;
	case "config":
		return;
	break;
	case "gotoAnchor":
		return "";
	break;
	case "clone":
		return clone(cloneID());
	break;
	case "init":
		usual();
		gWidth = 0;
		gHeight = 0;
		gfxChildCount = 0;
		gfxChildren = "";
		/* Use document colors */
		SGMLBuildDoc_setColors();
		print("[GRAPHICS] init: done\n");
		return;
	break;
	}
	usual();

