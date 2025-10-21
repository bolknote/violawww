
	switch (arg[0]) {
	case "_cancel":
	case "_ok":
		send(parent(), arg[0]);
		return;
	break;
	}
	usual();
