
	switch (arg[0]) {
	case "i":
	case "I":
	case "T":
	case "TI":
	case "TD":
	case "TT":
		/* Ignore parser bookkeeping messages */
		return;
	break;
	case "addChild":
		/* Child primitive registering itself - store in array */
		childObj = arg[1];
		gfxChildArr[gfxChildCount] = childObj;
		gfxChildCount = gfxChildCount + 1;
		return;
	break;
	case "setCurrentGfx":
		/* Set current graphics container for children to find */
		_currentGfx = arg[1];
		return;
	break;
	case "getCurrentGfx":
		/* Return current graphics container */
		return _currentGfx;
	break;
	case "setBGColor":
		/* Set background color from BGCOLOR child tag */
		set("BGColor", arg[1]);
		return;
	break;
	case "expose":
		/* Let parent class draw background first */
		usual();
		/* Container draws all children using array */
		if (gfxChildCount > 0) {
			/* Draw each child from array */
			for (childNum = 0; childNum < gfxChildCount; childNum++) {
				childName = gfxChildArr[childNum];
				if (childName != "" && exist(childName) == 1) {
						/* Query child for shape type, color, and transforms */
						shapeType = send(childName, "getShapeType");
						shapeFG = send(childName, "getFG");
						shapeBD = send(childName, "getBD");
						/* Get rotation for all 3 axes */
						shapeRotX = send(childName, "getRotX");
						shapeRotY = send(childName, "getRotY");
						shapeRotZ = send(childName, "getRotZ");
						/* Get scale for all 3 axes */
						shapeSX = send(childName, "getScaleX");
						shapeSY = send(childName, "getScaleY");
						shapeSZ = send(childName, "getScaleZ");
						/* Get axis center */
						shapeAX = send(childName, "getAxisX");
						shapeAY = send(childName, "getAxisY");
						shapeAZ = send(childName, "getAxisZ");
						
						/* Set color */
						if (shapeFG != "") {
							set("FGColor", shapeFG);
						}
						
						/* Check if we have transforms to apply */
						/* Handle empty/missing values - use defaults */
						hasTransform = 0;
						/* Rotation X (perspective tilt forward/back) */
						if (isBlank(shapeRotX) == 1) {
							rotXVal = 0.0;
						} else {
							rotXVal = float(shapeRotX);
						}
						/* Rotation Y (perspective turn left/right) */
						if (isBlank(shapeRotY) == 1) {
							rotYVal = 0.0;
						} else {
							rotYVal = float(shapeRotY);
						}
						/* Rotation Z (2D rotation on screen) */
						if (isBlank(shapeRotZ) == 1) {
							rotZVal = 0.0;
						} else {
							rotZVal = float(shapeRotZ);
						}
						/* For backward compatibility */
						rotVal = rotZVal;
						/* Scale X */
						if (isBlank(shapeSX) == 1 || shapeSX == "0" || shapeSX == "0.0") {
							sxVal = 1.0;
						} else {
							sxVal = float(shapeSX);
						}
						/* Scale Y */
						if (isBlank(shapeSY) == 1 || shapeSY == "0" || shapeSY == "0.0") {
							syVal = 1.0;
						} else {
							syVal = float(shapeSY);
						}
						/* Scale Z (affects perspective depth) */
						if (isBlank(shapeSZ) == 1 || shapeSZ == "0" || shapeSZ == "0.0") {
							szVal = 1.0;
						} else {
							szVal = float(shapeSZ);
						}
						/* Rotation Z: anything non-zero */
						if (rotZVal > 0.001 || rotZVal < -0.001) hasTransform = 1;
						/* Rotation X/Y: perspective transforms */
						if (rotXVal > 0.001 || rotXVal < -0.001) hasTransform = 1;
						if (rotYVal > 0.001 || rotYVal < -0.001) hasTransform = 1;
						/* Scale: anything not 1.0 */
						if (sxVal > 1.001 || sxVal < 0.999) hasTransform = 1;
						if (syVal > 1.001 || syVal < 0.999) hasTransform = 1;
						if (szVal > 1.001 || szVal < 0.999) hasTransform = 1;
						
						if (shapeType == "polygon") {
							/* Polygon uses points */
							numPoints = send(childName, "getPoints");
							shapeFG = send(childName, "getFG");
							if (shapeFG != "" && shapeFG != "0") {
								set("FGColor", shapeFG);
							}
							if (numPoints >= 2) {
								/* Get all points and optionally transform */
								for (pi = 0; pi < numPoints; pi++) {
									tpx[pi] = send(childName, "getPointX", pi);
									tpy[pi] = send(childName, "getPointY", pi);
									
							if (hasTransform == 1) {
									/* Apply scale then rotation around axis */
									tx = tpx[pi] - shapeAX;
									ty = tpy[pi] - shapeAY;
									tz = 0;
									nx = 0;
									ny = 0;
									nz = 0;
									/* Scale using float values */
									tx = tx * sxVal;
									ty = ty * syVal;
									tz = tz * szVal;
									/* Apply ROT Y (rotation around vertical axis - perspective left/right) */
									if (rotYVal > 0.001 || rotYVal < -0.001) {
										cosRY = cos(rotYVal);
										sinRY = sin(rotYVal);
										nx = (tx * cosRY) + (tz * sinRY);
										nz = ((0 - tx) * sinRY) + (tz * cosRY);
										tx = nx;
										tz = nz;
									}
									/* Apply ROT X (rotation around horizontal axis - perspective tilt) */
									if (rotXVal > 0.001 || rotXVal < -0.001) {
										cosRX = cos(rotXVal);
										sinRX = sin(rotXVal);
										ny = (ty * cosRX) - (tz * sinRX);
										nz = (ty * sinRX) + (tz * cosRX);
										ty = ny;
										tz = nz;
									}
									/* Apply ROT Z (2D rotation on screen) */
									if (rotZVal > 0.001 || rotZVal < -0.001) {
										cosR = cos(rotZVal);
										sinR = sin(rotZVal);
										nx = (tx * cosR) - (ty * sinR);
										ny = (tx * sinR) + (ty * cosR);
										tx = nx;
										ty = ny;
									}
									/* Perspective projection */
									perspD = 500;
									if (tz > 0.001 || tz < -0.001) {
										perspScale = perspD / (perspD + tz);
										tx = tx * perspScale;
										ty = ty * perspScale;
									}
									/* Translate back */
									tpx[pi] = int(tx + shapeAX);
									tpy[pi] = int(ty + shapeAY);
								}
								}
								/* Draw lines connecting all points */
								for (pi = 0; pi < numPoints - 1; pi++) {
									drawLine(tpx[pi], tpy[pi], tpx[pi + 1], tpy[pi + 1]);
								}
								/* Close polygon */
								if (numPoints >= 3) {
									drawLine(tpx[numPoints - 1], tpy[numPoints - 1], tpx[0], tpy[0]);
								}
							}
						} else {
							/* Other shapes use X/Y/W/H */
							shapeX = send(childName, "getX");
							shapeY = send(childName, "getY");
							shapeW = send(childName, "getW");
							shapeH = send(childName, "getH");
							
							if (hasTransform == 1) {
								/* Use center of shape as default axis if not specified */
								origAX = shapeAX;
								origAY = shapeAY;
								if (shapeAX == 0 && shapeAY == 0) {
									origAX = shapeX + shapeW / 2;
									origAY = shapeY + shapeH / 2;
								}
								
								/* For oval/circle, skip corner transformation and draw directly */
								if (shapeType == "circle" || shapeType == "oval") {
									/* Draw ellipse with 16-point polygon */
									centerX = origAX;
									centerY = origAY;
									radiusX = shapeW / 2;
									radiusY = shapeH / 2;
									
									for (ai = 0; ai < 16; ai++) {
										angle = ai * 22.5; /* 360/16 = 22.5 degrees */
										/* Start with ellipse point */
										tx = radiusX * cos(angle);
										ty = radiusY * sin(angle);
										tz = 0;
										nx = 0;
										ny = 0;
										nz = 0;
										/* Scale */
										tx = tx * sxVal;
										ty = ty * syVal;
										tz = tz * szVal;
										/* Apply ROT Y */
										if (rotYVal > 0.001 || rotYVal < -0.001) {
											cosRY = cos(rotYVal);
											sinRY = sin(rotYVal);
											nx = (tx * cosRY) + (tz * sinRY);
											nz = ((0 - tx) * sinRY) + (tz * cosRY);
											tx = nx;
											tz = nz;
										}
										/* Apply ROT X */
										if (rotXVal > 0.001 || rotXVal < -0.001) {
											cosRX = cos(rotXVal);
											sinRX = sin(rotXVal);
											ny = (ty * cosRX) - (tz * sinRX);
											nz = (ty * sinRX) + (tz * cosRX);
											ty = ny;
											tz = nz;
										}
										/* Apply ROT Z */
										if (rotZVal > 0.001 || rotZVal < -0.001) {
											cosR = cos(rotZVal);
											sinR = sin(rotZVal);
											nx = (tx * cosR) - (ty * sinR);
											ny = (tx * sinR) + (ty * cosR);
											tx = nx;
											ty = ny;
										}
										/* Perspective */
										perspD = 500;
										if (tz > 0.001 || tz < -0.001) {
											perspScale = perspD / (perspD + tz);
											tx = tx * perspScale;
											ty = ty * perspScale;
										}
										ellipseX[ai] = int(centerX + tx);
										ellipseY[ai] = int(centerY + ty);
									}
									/* Draw the ellipse outline */
									for (ai = 0; ai < 15; ai++) {
										drawLine(ellipseX[ai], ellipseY[ai], ellipseX[ai + 1], ellipseY[ai + 1]);
									}
									drawLine(ellipseX[15], ellipseY[15], ellipseX[0], ellipseY[0]);
								} else {
									/* For rect/line, transform 4 corners */
									cx[0] = shapeX;
									cy[0] = shapeY;
									cx[1] = shapeX + shapeW;
									cy[1] = shapeY;
									cx[2] = shapeX + shapeW;
									cy[2] = shapeY + shapeH;
									cx[3] = shapeX;
									cy[3] = shapeY + shapeH;
								
									/* Transform all 4 corners */
									for (ci = 0; ci < 4; ci++) {
										tx = cx[ci] - origAX;
										ty = cy[ci] - origAY;
										tz = 0;
										nx = 0;
										ny = 0;
										nz = 0;
										/* Scale using float values */
										tx = tx * sxVal;
										ty = ty * syVal;
										tz = tz * szVal;
										/* Apply ROT Y (rotation around vertical axis - perspective left/right) */
										if (rotYVal > 0.001 || rotYVal < -0.001) {
											cosRY = cos(rotYVal);
											sinRY = sin(rotYVal);
											nx = (tx * cosRY) + (tz * sinRY);
											nz = ((0 - tx) * sinRY) + (tz * cosRY);
											tx = nx;
											tz = nz;
										}
										/* Apply ROT X (rotation around horizontal axis - perspective tilt) */
										if (rotXVal > 0.001 || rotXVal < -0.001) {
											cosRX = cos(rotXVal);
											sinRX = sin(rotXVal);
											ny = (ty * cosRX) - (tz * sinRX);
											nz = (ty * sinRX) + (tz * cosRX);
											ty = ny;
											tz = nz;
										}
										/* Apply ROT Z (2D rotation on screen) */
										if (rotZVal > 0.001 || rotZVal < -0.001) {
											cosR = cos(rotZVal);
											sinR = sin(rotZVal);
											nx = (tx * cosR) - (ty * sinR);
											ny = (tx * sinR) + (ty * cosR);
											tx = nx;
											ty = ny;
										}
										/* Perspective projection */
										perspD = 500;
										if (tz > 0.001 || tz < -0.001) {
											perspScale = perspD / (perspD + tz);
											tx = tx * perspScale;
											ty = ty * perspScale;
										}
										/* Translate back */
										cx[ci] = int(tx + origAX);
										cy[ci] = int(ty + origAY);
									}
								
								/* Draw transformed shape as polygon */
								if (shapeType == "rect") {
									/* Draw filled polygon for rotated rect */
									drawFillPolygon(cx[0], cy[0], cx[1], cy[1], cx[2], cy[2], cx[3], cy[3]);
									/* Border with different color if set */
									if (shapeBD != "" && shapeBD != "0") {
										set("FGColor", shapeBD);
										drawLine(cx[0], cy[0], cx[1], cy[1]);
										drawLine(cx[1], cy[1], cx[2], cy[2]);
										drawLine(cx[2], cy[2], cx[3], cy[3]);
										drawLine(cx[3], cy[3], cx[0], cy[0]);
									}
								}
									if (shapeType == "line") {
										drawLine(cx[0], cy[0], cx[2], cy[2]);
									}
								} /* end else rect/line */
							} else {
								/* No transform - draw normally */
								/* Helper: check if border color is valid (not empty, not "0") */
								hasBorder = 0;
								if (shapeBD != "" && shapeBD != "0") {
									hasBorder = 1;
								}
								
								if (shapeType == "rect") {
									/* Draw border first if set (outside the fill) */
									if (hasBorder == 1) {
										set("FGColor", shapeBD);
										/* Draw 2-pixel thick border outside */
										drawFillRect(shapeX - 2, shapeY - 2, shapeX + shapeW + 2, shapeY + shapeH + 2);
									}
									/* Draw fill on top */
									if (shapeFG != "") {
										set("FGColor", shapeFG);
									}
									drawFillRect(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
								}
								if (shapeType == "circle") {
									if (hasBorder == 1) {
										set("FGColor", shapeBD);
										drawFillOval(shapeX - 2, shapeY - 2, shapeX + shapeW + 2, shapeY + shapeH + 2);
									}
									if (shapeFG != "") {
										set("FGColor", shapeFG);
									}
									drawFillOval(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
								}
								if (shapeType == "oval") {
									if (hasBorder == 1) {
										set("FGColor", shapeBD);
										drawFillOval(shapeX - 2, shapeY - 2, shapeX + shapeW + 2, shapeY + shapeH + 2);
									}
									if (shapeFG != "") {
										set("FGColor", shapeFG);
									}
									drawFillOval(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
								}
							if (shapeType == "line") {
								drawLine(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
							}
							if (shapeType == "button") {
								/* Draw button with 3D effect */
								btnBG = send(childName, "getBG");
								btnLabel = send(childName, "getLabel");
								isPressed = 0;
								if (_pressedButton == childName) {
									isPressed = 1;
								}
								/* Button background */
								if (btnBG != "" && btnBG != "0") {
									set("FGColor", btnBG);
								} else {
									set("FGColor", "#d0d0d0");
								}
								drawFillRect(shapeX, shapeY, shapeX + shapeW, shapeY + shapeH);
								if (isPressed == 1) {
									/* Pressed: dark on top/left, light on bottom/right */
									set("FGColor", "#606060");
									drawLine(shapeX, shapeY, shapeX + shapeW, shapeY);
									drawLine(shapeX, shapeY, shapeX, shapeY + shapeH);
									set("FGColor", "#ffffff");
									drawLine(shapeX, shapeY + shapeH, shapeX + shapeW, shapeY + shapeH);
									drawLine(shapeX + shapeW, shapeY, shapeX + shapeW, shapeY + shapeH);
								} else {
									/* Normal: light on top/left, dark on bottom/right */
									set("FGColor", "#ffffff");
									drawLine(shapeX, shapeY, shapeX + shapeW, shapeY);
									drawLine(shapeX, shapeY, shapeX, shapeY + shapeH);
									set("FGColor", "#808080");
									drawLine(shapeX, shapeY + shapeH, shapeX + shapeW, shapeY + shapeH);
									drawLine(shapeX + shapeW, shapeY, shapeX + shapeW, shapeY + shapeH);
								}
								/* Label text */
								if (btnLabel != "" && btnLabel != "0") {
									if (shapeFG != "" && shapeFG != "0") {
										set("FGColor", shapeFG);
									} else {
										set("FGColor", "black");
									}
									/* Center text in button */
									/* drawText draws from baseline, so we need to account for descent */
									labelW = textWidth(1, btnLabel);
									labelH = charHeight(1);
									textX = shapeX + ((shapeW - labelW) / 2);

									textY = shapeY + ((shapeH - labelH) / 2);
									/* Shift text when pressed */
									if (isPressed == 1) {
										textX = textX + 1;
										textY = textY + 1;
									}
									drawText(textX, textY, 1, btnLabel);
								}
							}
						}
					}
				}
			}
		}
		return;
	break;
	case "D":
		/* Done building */
		return 1;
	break;
	case "R":
		/* arg[1]	y
		 * arg[2]	width
		 */
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
		return vspan;
	break;
	case "AA":
		/* On first attribute, register self as current graphics container */
		if (_registeredAsCurrent == 0) {
			_registeredAsCurrent = 1;
			send("HTML_graphics", "setCurrentGfx", self());
		}
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
		_registeredAsCurrent = 0;
		_pressedButton = "";
		/* Use document colors */
		SGMLBuildDoc_setColors();
		return;
	break;
	case "buttonPress":
		/* Find button under mouse and mark as pressed */
		mx = arg[1];
		my = arg[2];
		for (bi = 0; bi < gfxChildCount; bi++) {
			btn = gfxChildArr[bi];
			if (btn != "" && exist(btn) == 1) {
				if (send(btn, "getShapeType") == "button") {
					bx = send(btn, "getX");
					by = send(btn, "getY");
					bw = send(btn, "getW");
					bh = send(btn, "getH");
					if (mx >= bx && mx <= bx + bw && my >= by && my <= bh + by) {
						_pressedButton = btn;
						send(self(), "expose");
						return;
					}
				}
			}
		}
		return;
	break;
	case "buttonRelease":
		/* Release button and trigger action */
		if (_pressedButton != "" && exist(_pressedButton) == 1) {
			href = send(_pressedButton, "getHref");
			_pressedButton = "";
			send(self(), "expose");
			if (href != "" && href != "0") {
				/* Use www object to load URL */
				send("www", "show", href);
			}
		}
		return;
	break;
	case "mouseMove":
		/* Show hint for button under mouse */
		mx = arg[1];
		my = arg[2];
		for (bi = 0; bi < gfxChildCount; bi++) {
			btn = gfxChildArr[bi];
			if (btn != "" && exist(btn) == 1) {
				if (send(btn, "getShapeType") == "button") {
					bx = send(btn, "getX");
					by = send(btn, "getY");
					bw = send(btn, "getW");
					bh = send(btn, "getH");
					if (mx >= bx && mx <= bx + bw && my >= by && my <= by + bh) {
						hint = send(btn, "getHint");
						if (hint != "" && hint != "0") {
							send("www.mesg.tf", "show", hint);
						}
						return;
					}
				}
			}
		}
		/* Clear hint when not over button */
		send("www.mesg.tf", "show", "");
		return;
	break;
	}
	usual();

