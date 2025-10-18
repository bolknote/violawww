/*
 * class        : pane
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_pane;
long helper_pane_get();
long helper_pane_set();

enum PaneConfigTypes {
    PANE_CONFIG_FREE,
    PANE_CONFIG_N2S,
    PANE_CONFIG_S2N,
    PANE_CONFIG_W2E,
    PANE_CONFIG_E2W,
    PANE_CONFIG_N2S_EDGE,
    PANE_CONFIG_S2N_EDGE,
    PANE_CONFIG_W2E_EDGE,
    PANE_CONFIG_E2W_EDGE,
    PANE_CONFIG_CENTER,
};
extern char* paneConfigStr[];

long meth_pane_config();
long meth_pane_clone();
long meth_pane_clone2();
long meth_pane_expose();
long meth_pane_get();
long meth_pane_initialize();
long meth_pane_render();
long meth_pane_set();
