//===============================================
#include "GProcessSQLite.h"
#include "GSQLite.h"
//===============================================
static GProcessO* m_GProcessSQLiteO = 0;
//===============================================
static void GProcessSQLite_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessSQLite_New() {
    GProcessO* lParent = GProcess_New();
    GProcessSQLiteO* lChild = (GProcessSQLiteO*)malloc(sizeof(GProcessSQLiteO));

    lChild->m_parent = lParent;

    lParent->m_child = lChild;
    lParent->Delete = GProcessSQLite_Delete;
    lParent->Run = GProcessSQLite_Run;
    return lParent;
}
//===============================================
void GProcessSQLite_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessSQLite() {
    if(m_GProcessSQLiteO == 0) {
        m_GProcessSQLiteO = GProcessSQLite_New();
    }
    return m_GProcessSQLiteO;
}
//===============================================
static void GProcessSQLite_Run(int argc, char** argv) {
	GSQLite()->Version();
	GSQLite()->Open("ELEPHANT", "data/data/elephant.db");
	GSQLite()->Close("ELEPHANT");
}
//===============================================
