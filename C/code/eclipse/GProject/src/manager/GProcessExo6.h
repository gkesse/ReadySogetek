//===============================================
#ifndef _GProcessExo6_
#define _GProcessExo6_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo6O GProcessExo6O;
//===============================================
struct _GProcessExo6O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo6_New();
void GProcessExo6_Delete(GProcessO* obj);
GProcessO* GProcessExo6();
//===============================================
#endif
//===============================================
