//===============================================
#include "GProcessExo4.h"
//===============================================
static GProcessO* m_GProcessExo4O = 0;
//===============================================
void GProcessExo4_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessExo4_New() {
    GProcessO* lParent = GProcess_New();
    GProcessExo4O* lChild = (GProcessExo4O*)malloc(sizeof(GProcessExo4O));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessExo4_Delete;
    lParent->Run = GProcessExo4_Run;
    return lParent;
}
//===============================================
void GProcessExo4_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessExo4() {
    if(m_GProcessExo4O == 0) {
        m_GProcessExo4O = GProcessExo4_New();
    }
    return m_GProcessExo4O;
}

//===============================================
void GProcessExo4_Run(int argc, char** argv) {
	int lInt;
	int lParity;
	int lOk;

	printf("### Recherche de parite: Pair/Impair\n\n");

	while(1) {
		printf("Pour quitter: Saisir une lettre\n");
		printf("Saisir un entier: ");
		lOk = scanf("%d", &lInt);
		fflush(stdin);
		if(lOk == 0) break;
		lParity = lInt % 2;
		if(lParity == 0) printf("Le nombre (%d) est un nombre (Pair)\n", lInt);
		else printf("Le nombre (%d) est un nombre (Impair)\n", lInt);
		printf("\n");
	}
}
//===============================================
