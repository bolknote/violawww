/*		Wayback Machine (Internet Archive) Integration		HTWayback.h
**		==============================================
**
**	This module provides integration with the Internet Archive's
**	Wayback Machine for accessing archived versions of websites.
*/

#ifndef HTWAYBACK_H
#define HTWAYBACK_H

#include "HTUtils.h"

/*	Wayback Machine API configuration
*/
#define WAYBACK_API_HOST "web.archive.org"

/*	Check if URL is available in Wayback Machine
**	---------------------------------------------
**
**  On entry:
**	url		The URL to check (e.g., "http://example.com/page")
**
**  On exit:
**	returns		Wayback URL if available (must be freed by caller)
**			NULL if not found or error
*/
PUBLIC char* HTWaybackCheck PARAMS((CONST char* url));

#endif /* HTWAYBACK_H */

