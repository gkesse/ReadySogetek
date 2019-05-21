//===============================================
#ifndef _GProcessExo51_
#define _GProcessExo51_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessExo51O GProcessExo51O;
//===============================================
struct _GProcessExo51O {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessExo51_New();
void GProcessExo51_Delete(GProcessO* obj);
GProcessO* GProcessExo51();
//===============================================
#endif
//===============================================
