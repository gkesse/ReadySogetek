//===============================================
#ifndef _GProcessExo50_
#define _GProcessExo50_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo50O GProcessExo50O;
//===============================================
struct _GProcessExo50O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo50_New();
void GProcessExo50_Delete(GProcessO* obj);
GProcessO* GProcessExo50();
//===============================================
#endif
//===============================================
