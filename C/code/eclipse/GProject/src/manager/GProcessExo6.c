//===============================================
#include "GProcessExo6.h"
//===============================================
static GProcessO* m_GProcessExo6O = 0;
//===============================================
void GProcessExo6_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessExo6_New() {
    GProcessO* lParent = GProcess_New();
    GProcessExo6O* lChild = (GProcessExo6O*)malloc(sizeof(GProcessExo6O));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessExo6_Delete;
    lParent->Run = GProcessExo6_Run;
    return lParent;
}
//===============================================
void GProcessExo6_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO  * GProcessExo6() {
    if(m_GProcessExo6O == 0) {
        m_GProcessExo6O = GProcessExo6_New();
    }
    return m_GProcessExo6O;
}

//===============================================
void GProcessExo6_Run(int argc, char** argv) {
	int lDataMap[128];
	int lDataMin;
	int lDataMax;
	int lOk;

	printf("### Plus grand et plus petit d'une suite d'entiers\n\n");

	printf("Saisir une suite d'entiers:\n");
}
//===============================================
