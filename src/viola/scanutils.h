long getIdent();
long tokenize(char *identStr);
void set_parsing_string(char *s);
/*HashEntry *_getIdent_entry;*/
/*#define getIdent(identStr) \
((_getIdent_entry = symStr2ID->get(symStr2ID, (long)identStr))?\
_getIdent_entry->val : NULL)*/

