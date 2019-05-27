//===============================================
#ifndef _GProcessMap_
#define _GProcessMap_
//===============================================
#include "GProcess.h"
#include "GMap.h"
//===============================================
typedef struct _GProcessMapO GProcessMapO;
typedef struct _GMapO_GProcessMap_GINT_GCHAR GMapO_GProcessMap_GINT_GCHAR;
typedef struct _GMapO_GProcessMap_GCHAR_PTR_GCHAR_PTR GMapO_GProcessMap_GCHAR_PTR_GCHAR_PTR;
//===============================================
struct _GProcessMapO {
    GProcessO* m_parent;
    void (*ShowMap)(GMapO(GProcessMap_GINT_GCHAR)* obj);
    void (*ShowMap2)(GMapO(GProcessMap_GCHAR_PTR_GCHAR_PTR)* obj);
};
//===============================================
GProcessO* GProcessMap_New();
void GProcessMap_Delete(GProcessO* obj);
GProcessO* GProcessMap();
//===============================================
#endif
//===============================================
