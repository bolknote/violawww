/*
 * class        : pane
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_pane;
long helper_pane_get(VObj*, Packet*, int, Packet*, long);
long helper_pane_set(VObj*, Packet*, int, Packet*, long);

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

long meth_pane_config(VObj *, Packet *, int, Packet *);
long meth_pane_clone(VObj *, Packet *, int, Packet *);
long meth_pane_clone2(VObj *, Packet *, int, Packet *);
long meth_pane_expose(VObj *, Packet *, int, Packet *);
long meth_pane_get(VObj *, Packet *, int, Packet *);
long meth_pane_initialize(VObj *, Packet *, int, Packet *);
long meth_pane_render(VObj *, Packet *, int, Packet *);
long meth_pane_set(VObj *, Packet *, int, Packet *);
