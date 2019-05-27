//===============================================
#ifndef _GProcessMap_
#define _GProcessMap_
//===============================================
#include "GProcess.h"
#include "GMap.h"
//===============================================
typedef struct _GProcessMapO GProcessMapO;
typedef struct _GMapO_GINT_GCHAR GMapO_GINT_GCHAR;
typedef struct _GMapO_GCHAR_PTR_GCHAR_PTR GMapO_GCHAR_PTR_GCHAR_PTR;
//===============================================
struct _GProcessMapO {
    GProcessO* m_parent;
    void (*ShowMap)(GMapO(GINT_GCHAR)* obj);
    void (*ShowMap2)(GMapO(GCHAR_PTR_GCHAR_PTR)* obj);
};
//===============================================
GProcessO* GProcessMap_New();
void GProcessMap_Delete(GProcessO* obj);
GProcessO* GProcessMap();
//===============================================
#endif
//===============================================
