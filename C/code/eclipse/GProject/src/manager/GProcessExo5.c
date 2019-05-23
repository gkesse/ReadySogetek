//===============================================
#include "GProcessExo5.h"
//===============================================
static GProcessO* m_GProcessExo5O = 0;
//===============================================
void GProcessExo5_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessExo5_New() {
    GProcessO* lParent = GProcess_New();
    GProcessExo5O* lChild = (GProcessExo5O*)malloc(sizeof(GProcessExo5O));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessExo5_Delete;
    lParent->Run = GProcessExo5_Run;
    return lParent;
}
//===============================================
void GProcessExo5_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessExo5() {
    if(m_GProcessExo5O == 0) {
        m_GProcessExo5O = GProcessExo5_New();
    }
    return m_GProcessExo5O;
}

//===============================================
void GProcessExo5_Run(int argc, char** argv) {
	int lDataMap[3];
	int lDataMax;
	int lOk;

	printf("### Plus grand de trois entiers saisis\n\n");

	printf("Saisir trois entiers:\n");

	for(int i = 0; i < 3; i++) {
		lOk = scanf("%d", &lDataMap[i]);
		fflush(stdin);
		if(lOk == 0) {printf("[ ERREUR ]: Erreur de saisie...\n"); exit(0);}
	}

	printf("Vous avez saisis:\n");

	for(int i = 0; i < 3; i++) {
		if(i != 0) printf("; ");
		printf("%d", lDataMap[i]);
	}
	printf("\n");

	lDataMax = lDataMap[0];

	for(int i = 1; i < 3; i++) {
		int lData = lDataMap[i];
		if(lData > lDataMax) lDataMax = lData;
	}

	printf("Le plus grand entier est: %d\n", lDataMax);
}
//===============================================
