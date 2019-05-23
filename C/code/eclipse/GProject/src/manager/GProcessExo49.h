//===============================================
#ifndef _GProcessExo49_
#define _GProcessExo49_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo49O GProcessExo49O;
//===============================================
struct _GProcessExo49O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo49_New();
void GProcessExo49_Delete(GProcessO* obj);
GProcessO* GProcessExo49();
//===============================================
#endif
//===============================================
