//===============================================
#ifndef _GProcessExo3_
#define _GProcessExo3_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo3O GProcessExo3O;
//===============================================
struct _GProcessExo3O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo3_New();
void GProcessExo3_Delete(GProcessO* obj);
GProcessO* GProcessExo3();
//===============================================
#endif
//===============================================
