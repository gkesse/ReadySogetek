//===============================================
#include "GProcessMap.h"
//===============================================
typedef int GINT;
typedef char GCHAR;
typedef char* GCHAR_PTR;
//===============================================
GDECLARE_MAP(GINT, GCHAR, GProcessMap_GINT_GCHAR)
GDEFINE_MAP(GINT, GCHAR, GProcessMap_GINT_GCHAR)
//===============================================
GDECLARE_MAP(GCHAR_PTR, GCHAR_PTR, GProcessMap_GCHAR_PTR_GCHAR_PTR)
GDEFINE_MAP(GCHAR_PTR, GCHAR_PTR, GProcessMap_GCHAR_PTR_GCHAR_PTR)
//===============================================
static GProcessO* m_GProcessMapO = 0;
//===============================================
void GProcessMap_Run(int argc, char** argv);
void GProcessMap_ShowMap(GMapO(GProcessMap_GINT_GCHAR)* obj);
void GProcessMap_ShowMap2(GMapO(GProcessMap_GCHAR_PTR_GCHAR_PTR)* obj);
//===============================================
GProcessO* GProcessMap_New() {
    GProcessO* lParent = GProcess_New();
    GProcessMapO* lChild = (GProcessMapO*)malloc(sizeof(GProcessMapO));

    lChild->m_parent = lParent;
    lChild->ShowMap = GProcessMap_ShowMap;
    lChild->ShowMap2 = GProcessMap_ShowMap2;

    lParent->m_child = lChild;
    lParent->Delete = GProcessMap_Delete;
    lParent->Run = GProcessMap_Run;
    return lParent;
}
//===============================================
void GProcessMap_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessMap() {
    if(m_GProcessMapO == 0) {
        m_GProcessMapO = GProcessMap_New();
    }
    return m_GProcessMapO;
}
//===============================================
void GProcessMap_Run(int argc, char** argv) {
	GProcessMapO* lProcessMap = m_GProcessMapO->m_child;

	GMapO(GProcessMap_GINT_GCHAR)* lMap = GMap_New_GProcessMap_GINT_GCHAR();
	lMap->SetData(lMap, 0, 'A');
	lMap->SetData(lMap, 1, 'B');
	lMap->SetData(lMap, 2, 'C');
	lMap->SetData(lMap, 3, 'D');
	lMap->Size(lMap);
	lProcessMap->ShowMap(lMap);
	lMap->Delete(lMap);

	GMapO(GProcessMap_GCHAR_PTR_GCHAR_PTR)* lMap2 = GMap_New_GProcessMap_GCHAR_PTR_GCHAR_PTR();
	lMap2->SetData(lMap2, "Nom", "KESSE");
	lMap2->SetData(lMap2, "Prenom", "Gerard");
	lMap2->SetData(lMap2, "Email", "gerard.kesse@readydev.com");
	lMap2->SetData(lMap2, "Diplome", "Ingenieur");
	lMap2->SetData(lMap2, "Formation", "Informatique Industrielle");
	lMap2->SetData(lMap2, "Ecole", "Polytech'Montpellier");
	lMap2->Size(lMap2);
	lProcessMap->ShowMap2(lMap2);
	lMap2->Delete(lMap2);
}
//===============================================
void GProcessMap_ShowMap(GMapO(GProcessMap_GINT_GCHAR)* obj) {
	GMapNodeO(GProcessMap_GINT_GCHAR)* lNext = obj->m_head;
	while(lNext != 0) {
		int lKey = lNext->m_key;
		char lValue = lNext->m_value;
		printf("[ MAP_1 ] %d : %c...\n", lKey, lValue);
		lNext = lNext->m_next;
	}
	printf("\n");
}
//===============================================
void GProcessMap_ShowMap2(GMapO(GProcessMap_GCHAR_PTR_GCHAR_PTR)* obj) {
	GMapNodeO(GProcessMap_GCHAR_PTR_GCHAR_PTR)* lNext = obj->m_head;
	while(lNext != 0) {
		char* lKey = lNext->m_key;
		char* lValue = lNext->m_value;
		printf("[ MAP_1 ] %s : %s...\n", lKey, lValue);
		lNext = lNext->m_next;
	}
	printf("\n");
}
//===============================================
