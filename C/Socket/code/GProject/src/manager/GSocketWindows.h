#ifndef _GSocketWindows_
#define _GSocketWindows_
//===============================================
#include "GSocket.h"
//===============================================
typedef struct _GSocketWindowsO GSocketWindowsO;
//===============================================
struct _GSocketWindowsO {
    GSocketO* m_parent;
};
//===============================================
GSocketO* GSocketWindows_New();
void GSocketWindows_Delete(GSocketO* obj);
GSocketO* GSocketWindows();
//===============================================
#endif
//===============================================