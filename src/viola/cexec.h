#pragma once

typedef struct Packet Packet;
typedef struct Attr Attr;
typedef long VObj;
union PCode;

#define PCODE_IDX_SIZE 0
#define PCODE_IDX_REFC 1
#define PCODE_IDX_INSTR 2

typedef struct CallObjStack {
    int destroyed;
    VObj* obj;
} CallObjStack;

extern CallObjStack callObjStack[];
extern int callObjStackIdx;

/*notes:
 * pcode[0] stores size of pcode array
 * pcode[1] stores reference count to this pcode
 * pcode[2] start of instructions
 * ...
 */

extern Packet* codeExec(VObj* self, union PCode* pcode, union PCode* pcode_end,
                        Attr** varVectorp[]);
extern Packet* execObjScript(VObj* obj);
extern Packet* execObjClassScript(VObj* obj, Packet* result);
extern Packet* execScript(VObj* self, Packet* result, char* script);
extern void freeVarList(Attr* varlist);
extern void dumpVarList(Attr* varlist);
extern Attr* makeArgAttr(VObj* obj);
extern int makeArgList(VObj* self, int argc);
extern void freeArgList(VObj* self);

extern long sendMessagePackets(VObj* self, Packet* packets, int packetc);
extern long sendMessagePackets_result(VObj* self, Packet* packets, int packetc, Packet* result);
extern long sendMessageAndInts(VObj* self, char* messg, int* intArray, int intCount);
extern long sendMessage1(VObj* self, char* messg);
extern long sendMessage1_result(VObj* self, char* messg, Packet* result);
extern long sendMessage1N1str(VObj* self, char* messg, char* s1);
extern long sendMessage1N1str_result(VObj* self, char* messg, char* s1, Packet* result);
extern long sendMessage1N2str(VObj* self, char* messg, char* s1, char* s2);
extern long sendMessage1N2str_result(VObj* self, char* messg, char* s1, char* s2, Packet* result);
extern long sendMessage1N1int(VObj* self, char* messg, int i1);
extern long sendMessage1N1int_result(VObj* self, char* messg, int i1, Packet* result);
extern long sendMessage1N2int(VObj* self, char* messg, int i1, int i2);
extern long sendMessage1N4int(VObj* self, char* messg, int i1, int i2, int i3, int i4);
extern long sendMessage1chr(VObj* self, char ch);
extern long sendMessage1chr_result(VObj* self, char ch, Packet* result);
extern long sendTokenMessageAndInts(VObj* self, int tok, int* intArray, int intCount);
extern long sendTokenMessage_result(VObj* self, int tok, Packet* result);
extern long sendTokenMessage(VObj* self, int tok);
extern long sendTokenMessageN1int(VObj* self, int tok, int i1);

extern int flag_printExec;
extern char* passthru_argument;
extern int getVariable(Attr* varlist, char* name, Packet* result);
extern int setVariable(Attr* varlist, char* name, char* valp);
extern Attr* setVariable_STR(Attr* varlist, char* name, char* valp, int canFree);
extern Attr* setVariable_id_STR(Attr* attrp, int varid, char* valp, int canFree);
extern Attr* setVariable_INT(VObj* self, char* varname, int val);
extern long getVariable_id(Attr* varlist, int varid);

extern int destroyVariable(Attr* varlist, char* name, int retp);

/*extern int ASSERT();*/
#define ASSERT(t, mesg) NULL
