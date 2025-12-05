
	switch (arg[0]) {
	case "setCurrentPrimitive":
		_currentPrimitive = arg[1];
		return;
	break;
	case "getCurrentPrimitive":
		return _currentPrimitive;
	break;
	case "getShapeType":
		return "polygon";
	break;
	case "getX":
		/* Return bounding box X (min X of all points) */
		if (pointCount < 1) return 0;
		minVal = pointsX[0];
		for (i = 1; i < pointCount; i++) {
			if (pointsX[i] < minVal) minVal = pointsX[i];
		}
		return minVal;
	break;
	case "getY":
		/* Return bounding box Y (min Y of all points) */
		if (pointCount < 1) return 0;
		minVal = pointsY[0];
		for (i = 1; i < pointCount; i++) {
			if (pointsY[i] < minVal) minVal = pointsY[i];
		}
		return minVal;
	break;
	case "getW":
		/* Return bounding box width (maxX - minX) */
		if (pointCount < 1) return 0;
		minVal = pointsX[0];
		maxVal = pointsX[0];
		for (i = 1; i < pointCount; i++) {
			if (pointsX[i] < minVal) minVal = pointsX[i];
			if (pointsX[i] > maxVal) maxVal = pointsX[i];
		}
		return maxVal - minVal;
	break;
	case "getH":
		/* Return bounding box height (maxY - minY) */
		if (pointCount < 1) return 0;
		minVal = pointsY[0];
		maxVal = pointsY[0];
		for (i = 1; i < pointCount; i++) {
			if (pointsY[i] < minVal) minVal = pointsY[i];
			if (pointsY[i] > maxVal) maxVal = pointsY[i];
		}
		return maxVal - minVal;
	break;
	case "getPoints":
		/* Return number of points */
		return pointCount;
	break;
	case "getPointX":
		return pointsX[arg[1]];
	break;
	case "getPointY":
		return pointsY[arg[1]];
	break;
	case "getFG":
		return fgColor;
	break;
	case "getBD":
		return bdColor;
	break;
	case "getHint":
		return hintText;
	break;
	case "getRotX":
		return _rotX;
	break;
	case "getRotY":
		return _rotY;
	break;
	case "getRotZ":
		return _rotZ;
	break;
	case "getRot":
		return _rotZ;
	break;
	case "getScaleX":
		return _scaleX;
	break;
	case "getScaleY":
		return _scaleY;
	break;
	case "getScaleZ":
		return _scaleZ;
	break;
	case "getAxisX":
		return _axisX;
	break;
	case "getAxisY":
		return _axisY;
	break;
	case "getAxisZ":
		return _axisZ;
	break;
	case "expose":
		return;
	break;
	case "D":
		/* D not called for SGML_MIXED with children, registration happens in case 8 */
		return 1; /* Keep object alive */
	break;
	case 8:
		/* End of tag processing - register with parent now (for SGML_MIXED) */
		if (_savedParent != "" && _savedParent != "0" && _savedParent != "(NULL)") {
			send(_savedParent, "addChild", self());
		}
		return;
	break;
	case "R":
		return 0;
	break;
	case "AA":
		/* Register self as current primitive for child tags */
		send("HTML_polygon", "setCurrentPrimitive", self());
		/* Save parent on first attribute - registration happens in case 8 */
		if (_savedParent == "" || _savedParent == "0" || _savedParent == "(NULL)") {
			_savedParent = parent();
			if (_savedParent == "" || _savedParent == "0" || _savedParent == "(NULL)") {
				_savedParent = send("HTML_graphics", "getCurrentGfx");
			}
		}
		switch (arg[1]) {
		case "ID":
		case "NAME":
			tagID = arg[2];
			set("name", arg[2]);
		break;
		case "HINT":
			hintText = arg[2];
		break;
		}
		return;
	break;
	case "AI":
		return;
	break;
	case "addPoint":
		pointsX[pointCount] = int(arg[1]);
		pointsY[pointCount] = int(arg[2]);
		pointCount = pointCount + 1;
		return;
	break;
	case "setFGColor":
		fgColor = arg[1];
		return;
	break;
	case "setBDColor":
		bdColor = arg[1];
		return;
	break;
	case "setRotX":
		_rotX = float(arg[1]);
		return;
	break;
	case "setRotY":
		_rotY = float(arg[1]);
		return;
	break;
	case "setRotZ":
		_rotZ = float(arg[1]);
		return;
	break;
	case "setRot":
		if (isBlank(arg[1]) == 0) {
			_rotX = float(arg[1]);
		}
		if (isBlank(arg[2]) == 0) {
			_rotY = float(arg[2]);
		}
		if (isBlank(arg[3]) == 0) {
			_rotZ = float(arg[3]);
		}
		return;
	break;
	case "setScale":
		_scaleX = float(arg[1]);
		_scaleY = float(arg[2]);
		if (isBlank(arg[3]) == 0) {
			_scaleZ = float(arg[3]);
		}
		return;
	break;
	case "setAxis":
		_axisX = int(arg[1]);
		_axisY = int(arg[2]);
		if (isBlank(arg[3]) == 0) {
			_axisZ = int(arg[3]);
		} else {
			_axisZ = 0;
		}
		return;
	break;
	case "setHint":
		hintText = arg[1];
		return;
	break;
	case "setActionScript":
		/* Receive action script from ACTION child */
		_actionScript = arg[1];
		return;
	break;
	case "buttonRelease":
	case "buttonUp":
		/* Execute action script if defined */
		if (_actionScript != "" && _actionScript != "0") {
			execScript(_actionScript);
		}
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
		pointCount = 0;
		fgColor = "black";
		bdColor = "";
		hintText = "";
		_actionScript = "";
		_savedParent = "";
		_rotX = 0.0;
		_rotY = 0.0;
		_rotZ = 0.0;
		_scaleX = 1.0;
		_scaleY = 1.0;
		_scaleZ = 1.0;
		_axisX = 0;
		_axisY = 0;
		_axisZ = 0;
		return;
	break;
	}
	usual();

