#include "hotlist.h"
#include "sgml.h"
#include "../libWWW/HTUtils.h"

/* Forward declaration */
struct _HTParentAnchor;
typedef struct _HTParentAnchor HTParentAnchor;
struct _tag;
typedef struct _tag HTTag;

extern int printTagDelims;

typedef struct SGMLBuildInfoState {
    SGMLTagMappingInfo* tmi;
    int dataBuffIdx_localStart;
    int* localizingTagIDMap;
    char* tag;
    VObj* parent;
    VObj* obj;
    int y;
    int width;
    int height;
    int sub_y;
    int sub_width;
    int sub_height;
    VObj* insert;
    char* styleAttr; /* HTML style attribute value for minor matching */
} SGMLBuildInfoState;

/* SGMLBuildInfo
 */
typedef struct SGMLBuildInfo {
    SGMLDocMappingInfo* dmi;
    struct SGMLBuildInfoState stack[100]; /* limit on nesting depth */
    int stacki;
    int endP;
    VObj* caller;
} SGMLBuildInfo;

SGMLTagMappingInfo* findTMI(SGMLTagMappingInfo*, char*);

int init_html2(void);

VObj* HTMLBuildObj(SGMLBuildInfoState*, int, SGMLTagMappingInfo*);

VObj* html2_parseHTMLDocument(VObj*, char*, char**, char**, int, int, char*);
void CB_HTML_new(void);
void CB_HTML_data(char*, int);
void CB_HTML_stag(int, BOOL*, char**, HTTag*);
void CB_HTML_etag(int);
void CB_HTML_end(void);

void html2_set_document_charset(const char* charset);
void html2_apply_pending_title(HTParentAnchor* anchor);
char* html2_get_pending_title(void);

char* encodeURL(char*);
char* decodeURL(char*);

/* for libwww to call */

int http_progress_reporter_level;
int http_progress_expected_total_bytes;
int http_progress_total_bytes;
int http_progress_subtotal_bytes;

int http_progress_notify(int);
void user_alert(char*);
void user_message(char*);
int user_message_confirm(char*);
char* user_prompt_default(char*, char*);
char* user_prompt_password(char*);
void user_prompt_username_and_password(char*, char**, char**);

void nullifyCallerDataBuff(void);

Bool initHotList(void);
Bool addHotListItem(char* url, char* comment, char* date);
HotListItem* getNthHotListItem(int n);
Bool deleteHotListItem(int n);
int saveHotList(void);
char* dumpHotList(int mode);
char* HotList_nextLine(void);
