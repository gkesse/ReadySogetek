//===============================================
#include "GProcessSocket.h"
#include "GSocket.h"
//===============================================
static GProcessO* m_GProcessSocketO = 0;
//===============================================
void GProcessSocket_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessSocket_New() {
    GProcessO* lParent = GProcess_New();
    GProcessSocketO* lChild = (GProcessSocketO*)malloc(sizeof(GProcessSocketO));
    lChild->m_parent = lParent;
    lParent->m_child = lChild;
    lParent->Delete = GProcessSocket_Delete;
    lParent->Run = GProcessSocket_Run;
    return lParent;
}
//===============================================
void GProcessSocket_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessSocket() {
    if(m_GProcessSocketO == 0) {
        m_GProcessSocketO = GProcessSocket_New();
    }
    return m_GProcessSocketO;
}

//===============================================
void GProcessSocket_Run(int argc, char** argv) {
    GSocket()->Start();
    GSocket()->Socket();
    GSocket()->Bind();
    GSocket()->Listen();
    GSocket()->Accept();
    GSocket()->Connect();
    GSocket()->Clean();
}
//===============================================
