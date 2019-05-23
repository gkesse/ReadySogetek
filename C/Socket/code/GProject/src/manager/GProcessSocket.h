//===============================================
#ifndef _GProcessSocket_
#define _GProcessSocket_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessSocketO GProcessSocketO;
//===============================================
struct _GProcessSocketO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessSocket_New();
void GProcessSocket_Delete(GProcessO* obj);
GProcessO* GProcessSocket();
//===============================================
#endif
//===============================================
