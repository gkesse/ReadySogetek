//===============================================
#include "GProcessExo49.h"
//===============================================
typedef struct _GNoeud GNoeud;
typedef struct _GNoeud* GArbre;
//===============================================
struct _GNoeud {
	char* sValeur;
	GNoeud* fils_g;
	GNoeud* fils_d;
};
//===============================================
static GProcessO* m_GProcessExo49O = 0;
//===============================================
void GProcessExo49_Run(int argc, char** argv);
//===============================================
GArbre ajouter(char* sAjout, GArbre tree);
void afficher(GArbre tree);
//===============================================
GProcessO* GProcessExo49_New() {
	GProcessO* lParent = GProcess_New();
	GProcessExo49O* lChild = (GProcessExo49O*)malloc(sizeof(GProcessExo49O));
	lChild->m_parent = lParent;
	lParent->m_child = lChild;
	lParent->Delete = GProcessExo49_Delete;
	lParent->Run = GProcessExo49_Run;
	return lParent;
}
//===============================================
void GProcessExo49_Delete(GProcessO* obj) {
	GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessExo49() {
	if(m_GProcessExo49O == 0) {
		m_GProcessExo49O = GProcessExo49_New();
	}
	return m_GProcessExo49O;
}

//===============================================
void GProcessExo49_Run(int argc, char** argv) {
	GArbre lTree = 0;

	printf("### Liste chainee | Ajouter une donnee\n\n");

	lTree = ajouter("Ubuntu", lTree);
	lTree = ajouter("Debian", lTree);
	lTree = ajouter("OpenSUSE", lTree);
	lTree = ajouter("REd Hat", lTree);

	afficher(lTree);
}
//===============================================
GArbre ajouter(char* sAjout, GArbre tree) {
	GNoeud* lNext;
	GNoeud* lNoeud;
	int lLength;

	lNoeud = (GNoeud*)malloc(sizeof(GNoeud));
	lLength = strlen(sAjout) + 1;
	lNoeud->sValeur = (char*)malloc(sizeof(char) * lLength);
	sprintf(lNoeud->sValeur, "%s", sAjout);
	lNoeud->fils_d = 0;
	lNoeud->fils_g = 0;

	if(tree == 0) {
		tree = lNoeud;
	}
	else {
		lNext = tree;
		while(lNext->fils_d != 0) {
			lNext = lNext->fils_d;
		}
		lNext->fils_d = lNoeud;
		lNoeud->fils_g = lNext;
	}

	return tree;
}
//===============================================
void afficher(GArbre tree) {
	GNoeud* lNoeud;

	lNoeud = tree;

	while(lNoeud != 0) {
		printf("%s\n", lNoeud->sValeur);
		lNoeud = lNoeud->fils_d;
	}
	printf("\n");
}
//===============================================
