/*
 * class        : cosmic
 * superClass	: NULL
 */

extern ClassInfo class_cosmic;
long helper_cosmic_get();
long helper_cosmic_set();

long meth_cosmic_clone();
long meth_cosmic_clone2();
long meth_cosmic_cloneID();
long meth_cosmic_create();
long meth_cosmic_debug();
long meth_cosmic_destroy();
long meth_cosmic_detach();
long meth_cosmic_exist();
long meth_cosmic_exit();
long meth_cosmic_freeSelf();
long meth_cosmic_info();
long meth_cosmic_interpret();
long meth_cosmic_loadObjFile();
long meth_cosmic_object();
long meth_cosmic_pop();
long meth_cosmic_push();
long meth_cosmic_quit();
long meth_cosmic_save();
long meth_cosmic_saveAs();
long meth_cosmic_saveObjFile();
long meth_cosmic_send();
long meth_cosmic_test1();
long meth_cosmic_test2();
long meth_cosmic_test3();
long meth_cosmic_test4();
long meth_cosmic_tweak();
long meth_cosmic_usual();

long meth_cosmic_modalExit();

void sendInitToChildren();
