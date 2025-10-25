/*	HyperText Transfer Protocol over SSL/TLS			HTTPS.h
**	=========================================
**
**	This module implements HTTPS protocol (HTTP over SSL/TLS)
*/

#ifndef HTTPS_H
#define HTTPS_H

#include "HTUtils.h"
#include "HTAccess.h"

#ifdef USE_SSL

/*	Load Document from HTTPS Server
**	-------------------------------
**
** On entry:
**	arg		URL to be loaded (https://...)
**	anAnchor	Anchor for the document
**	format_out	Desired output format
**	sink		Output stream
**
** On exit:
**	returns		HT_LOADED	Success
**			<0		Error
*/
extern int HTLoadHTTPS ARGS4(
    CONST char*,		arg,
    HTParentAnchor*,	anAnchor,
    HTFormat,			format_out,
    HTStream*,			sink
);

/*	Protocol descriptor
*/
extern HTProtocol HTTPS;

/* HTTP method constants (shared with HTTP.c) */
#define HTTP_METHOD_GET  0
#define HTTP_METHOD_POST 1

#endif /* USE_SSL */

#endif /* HTTPS_H */

