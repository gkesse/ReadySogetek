//===============================================
#include "GProcessMap.h"
//===============================================
static GProcessO* m_GProcessMapO = 0;
//===============================================
void GProcessMap_Run(int argc, char** argv);
void GProcessMap_ShowMap(GMapO(GINT_GCHAR)* obj);
//===============================================
GProcessO* GProcessMap_New() {
    GProcessO* lParent = GProcess_New();
    GProcessMapO* lChild = (GProcessMapO*)malloc(sizeof(GProcessMapO));

    lChild->m_parent = lParent;
    lChild->ShowMap = GProcessMap_ShowMap;

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
	GMapO(GINT_GCHAR)* lMap = GMap_New_GINT_GCHAR();
	lMap->SetData(lMap, 0, 'A');
	lMap->SetData(lMap, 1, 'B');
	lMap->SetData(lMap, 2, 'C');
	lMap->SetData(lMap, 3, 'D');
	lMap->Size(lMap);
	lMap->Delete(lMap);
}
//===============================================
void GProcessMap_ShowMap(GMapO(GINT_GCHAR)* obj) {

}
//===============================================
