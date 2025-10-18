#ifndef _VIOLA_HOTLIST_H_
#define _VIOLA_HOTLIST_H_

typedef struct HotListItem {
	char *url;
	char *comment;
	char *date; /* ugh */
	struct HotListItem *next;
} HotListItem;

extern HotListItem *theHotList;
extern int theHotListCount;

#endif /* _VIOLA_HOTLIST_H_ */
