//===============================================
#include "GProcessExo51.h"
//===============================================
static GProcessO* m_GProcessExo51O = 0;
//===============================================
void GProcessExo51_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessExo51_New() {
    GProcessO* lParent = GProcess_New();
    GProcessExo51O* lChild = (GProcessExo51O*)malloc(sizeof(GProcessExo51O));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessExo51_Delete;
    lParent->Run = GProcessExo51_Run;
    return lParent;
}
//===============================================
void GProcessExo51_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessExo51() {
    if(m_GProcessExo51O == 0) {
        m_GProcessExo51O = GProcessExo51_New();
    }
    return m_GProcessExo51O;
}

//===============================================
void GProcessExo51_Run(int argc, char** argv) {
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
