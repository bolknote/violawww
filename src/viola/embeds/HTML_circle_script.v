
	switch (arg[0]) {
	case "setCurrentPrimitive":
		_currentPrimitive = arg[1];
		return;
	break;
	case "getCurrentPrimitive":
		return _currentPrimitive;
	break;
	case "getShapeType":
		return "circle";
	break;
	case "getX":
		return posX;
	break;
	case "getY":
		return posY;
	break;
	case "getW":
		return sizeX;
	break;
	case "getH":
		return sizeY;
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
		/* Handler D not called for SGML_MIXED tags, registration done in AA */
		return 1; /* Keep object alive */
	break;
	case "R":
		return 0;
	break;
	case 8:
		/* End of tag processing - register with parent now */
		if (_savedParent != "" && _savedParent != "0" && _savedParent != "(NULL)") {
			send(_savedParent, "addChild", self());
		}
		return;
	break;
	case "AA":
		/* Register self as current primitive for child tags */
		send("HTML_circle", "setCurrentPrimitive", self());
		/* Save parent on first attribute */
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
	case "setPos":
		posX = int(arg[1]);
		posY = int(arg[2]);
		return;
	break;
	case "setSize":
		sizeX = int(arg[1]);
		sizeY = int(arg[2]);
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
		posX = 0;
		posY = 0;
		sizeX = 0;
		sizeY = 0;
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

