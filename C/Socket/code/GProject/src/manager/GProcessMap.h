//===============================================
#ifndef _GProcessMap_
#define _GProcessMap_
//===============================================
#include "GProcess.h"
#include "GMap.h"
//===============================================
typedef int GINT;
typedef char GCHAR;
GDECLARE_MAP(GINT, GCHAR, GINT_GCHAR)
GDEFINE_MAP(GINT, GCHAR, GINT_GCHAR)
//===============================================
typedef struct _GProcessMapO GProcessMapO;
//===============================================
struct _GProcessMapO {
    GProcessO* m_parent;
    void (*ShowMap)(GMapO(GINT_GCHAR)* obj);
};
//===============================================
GProcessO* GProcessMap_New();
void GProcessMap_Delete(GProcessO* obj);
GProcessO* GProcessMap();
//===============================================
#endif
//===============================================
