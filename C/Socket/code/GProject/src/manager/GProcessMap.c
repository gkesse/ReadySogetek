//===============================================
#include <GProcessMap.h>
#include <GMap.h>
//===============================================
static GProcessO* m_GProcessMapO = 0;
//===============================================
void GProcessMap_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessMap_New() {
    GProcessO* lParent = GProcess_New();
    GProcessMapO* lChild = (GProcessMapO*)malloc(sizeof(GProcessMapO));

    lChild->m_parent = lParent;

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
	GMapO* lMap = GMap_New();
	lMap->SetData(lMap, "Nom", "Gerard KESSE");
	lMap->SetData(lMap, "Nom", "Deborah YOBOUE");
	lMap->SetData(lMap, "Email", "gerard.kesse@readydev.com");
	lMap->SetData(lMap, "Ecole", "Polytech'Montpellier");
	lMap->Remove(lMap, "Ecole");
	lMap->Show(lMap);
	lMap->Size(lMap);
	lMap->Clear(lMap);
	lMap->Size(lMap);
	lMap->Delete(lMap);
}
//===============================================
