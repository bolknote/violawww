
	switch (arg[0]) {
	case "dismiss":
	case "saveAs":
	case "print":
		return send(parent(), arg[0]);
	break;
	}
	usual();
