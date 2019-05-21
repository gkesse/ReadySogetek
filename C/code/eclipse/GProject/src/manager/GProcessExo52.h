//===============================================
#ifndef _GProcessExo52_
#define _GProcessExo52_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo52O GProcessExo52O;
//===============================================
struct _GProcessExo52O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo52_New();
void GProcessExo52_Delete(GProcessO* obj);
GProcessO* GProcessExo52();
//===============================================
#endif
//===============================================
