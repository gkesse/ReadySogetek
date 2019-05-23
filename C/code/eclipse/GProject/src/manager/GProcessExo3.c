//===============================================
#include "GProcessExo3.h"
//===============================================
static GProcessO* m_GProcessExo3O = 0;
//===============================================
void GProcessExo3_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessExo3_New() {
    GProcessO* lParent = GProcess_New();
    GProcessExo3O* lChild = (GProcessExo3O*)malloc(sizeof(GProcessExo3O));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessExo3_Delete;
    lParent->Run = GProcessExo3_Run;
    return lParent;
}
//===============================================
void GProcessExo3_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessExo3() {
    if(m_GProcessExo3O == 0) {
        m_GProcessExo3O = GProcessExo3_New();
    }
    return m_GProcessExo3O;
}

//===============================================
void GProcessExo3_Run(int argc, char** argv) {
	char lPrint[128];
	char lChar_A = 0x41;
	char lChar_0 = 0x30;

	printf("### Gestion de code ASCII\n\n");

	for(int i = 0; i < 26; i++) {
		char lChar = lChar_A + i;
		sprintf(lPrint, "caractere = %c\tcode = %d\tcode hexa = %x", lChar, lChar, lChar);
		printf("%s\n", lPrint);
	}

	printf("\n");

	for(int i = 0; i < 10; i++) {
		char lChar = lChar_0 + i;
		sprintf(lPrint, "caractere = %c\tcode = %d\tcode hexa = %x", lChar, lChar, lChar);
		printf("%s\n", lPrint);
	}
}
//===============================================
