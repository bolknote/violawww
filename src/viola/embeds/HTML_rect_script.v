
	switch (arg[0]) {
	case "setCurrentPrimitive":
		_currentPrimitive = arg[1];
		return;
	break;
	case "getCurrentPrimitive":
		return _currentPrimitive;
	break;
	case "getShapeType":
		return "rect";
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
		/* Legacy - returns Z rotation */
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
	case 8:
		/* End of tag processing - register with parent now (for SGML_MIXED) */
		if (_savedParent != "" && _savedParent != "0" && _savedParent != "(NULL)") {
			send(_savedParent, "addChild", self());
		}
		return;
	break;
	case "D":
		/* D handler - registration fallback */
		return 1; /* Keep object alive */
	break;
	case "R":
		return 0;
	break;
	case "AA":
		/* Register self as current primitive for child tags */
		send("HTML_rect", "setCurrentPrimitive", self());
		/* Save parent on first attribute - parent() works during AA */
		if (_savedParent == "" || _savedParent == "0" || _savedParent == "(NULL)") {
			_savedParent = parent();
			/* If parent() failed, try getCurrentGfx from HTML_graphics class */
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
		case "PARENT":
			/* Find GRAPHICS by ID and register with it */
			parentID = arg[2];
			/* Store for later use in D handler */
			_parentID = parentID;
		break;
		case "X":
			posX = int(arg[2]);
		break;
		case "Y":
			posY = int(arg[2]);
		break;
		case "W":
			sizeX = int(arg[2]);
		break;
		case "H":
			sizeY = int(arg[2]);
		break;
		case "FGCOLOR":
			fgColor = arg[2];
		break;
		case "BDCOLOR":
			bdColor = arg[2];
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
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_pos == 1) {
				discoveryBroadcast(get("name"), "setPos", arg[1], arg[2]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setSize":
		sizeX = int(arg[1]);
		sizeY = int(arg[2]);
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_size == 1) {
				discoveryBroadcast(get("name"), "setSize", arg[1], arg[2]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setFGColor":
		fgColor = arg[1];
		if (discoveryIsRemote() == 0) {
			if (_sc_fgcolor == 1) {
				discoveryBroadcast(get("name"), "setFGColor", arg[1]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setBDColor":
		bdColor = arg[1];
		if (discoveryIsRemote() == 0) {
			if (_sc_bdcolor == 1) {
				discoveryBroadcast(get("name"), "setBDColor", arg[1]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setFilled":
		filled = int(arg[1]);
		return;
	break;
	case "setRotX":
		_rotX = float(arg[1]);
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_rot == 1) {
				discoveryBroadcast(get("name"), "setRotX", arg[1]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setRotY":
		_rotY = float(arg[1]);
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_rot == 1) {
				discoveryBroadcast(get("name"), "setRotY", arg[1]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setRotZ":
		_rotZ = float(arg[1]);
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_rot == 1) {
				discoveryBroadcast(get("name"), "setRotZ", arg[1]);
			}
		} else {
			send(_savedParent, "expose");
		}
		return;
	break;
	case "setRot":
		/* Accept X, Y, Z rotation values (legacy) */
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
		/* Broadcast if SC-enabled and not remote */
		if (discoveryIsRemote() == 0) {
			if (_sc_scale == 1) {
				discoveryBroadcast(get("name"), "setScale", arg[1], arg[2], arg[3]);
			}
		} else {
			send(_savedParent, "expose");
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
	case "enableSCPos":
		_sc_pos = 1;
		return;
	break;
	case "enableSCSize":
		_sc_size = 1;
		return;
	break;
	case "enableSCRot":
		_sc_rot = 1;
		return;
	break;
	case "enableSCScale":
		_sc_scale = 1;
		return;
	break;
	case "enableSCFGColor":
		_sc_fgcolor = 1;
		return;
	break;
	case "enableSCBDColor":
		_sc_bdcolor = 1;
		return;
	break;
	case "init":
		usual();
		/* Save parent now - it may become NULL later */
		_savedParent = parent();
		posX = 0;
		posY = 0;
		sizeX = 0;
		sizeY = 0;
		fgColor = "black";
		bdColor = "";
		hintText = "";
		_actionScript = "";
		_rotX = 0.0;
		_rotY = 0.0;
		_rotZ = 0.0;
		_scaleX = 1.0;
		_scaleY = 1.0;
		_scaleZ = 1.0;
		_axisX = 0;
		_axisY = 0;
		_axisZ = 0;
		/* SC flags - 0 = disabled, 1 = enabled */
		_sc_pos = 0;
		_sc_size = 0;
		_sc_rot = 0;
		_sc_scale = 0;
		_sc_fgcolor = 0;
		_sc_bdcolor = 0;
		return;
	break;
	}
	usual();

