
	switch (arg[0]) {
	case "_cancel":
	case "_ok":
	case "_cut":
	case "_clear":
		send(parent(), arg[0]);
		return;
	break;
	}
	usual();
