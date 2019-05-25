//===============================================
#include <GProcessSocketServer.h>
#include "GSocket.h"
//===============================================
static GProcessO* m_GProcessSocketServerO = 0;
//===============================================
void GProcessSocketServer_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessSocketServer_New() {
    GProcessO* lParent = GProcess_New();
    GProcessSocketServerO* lChild = (GProcessSocketServerO*)malloc(sizeof(GProcessSocketServerO));

    lChild->m_parent = lParent;

    lParent->m_child = lChild;
    lParent->Delete = GProcessSocketServer_Delete;
    lParent->Run = GProcessSocketServer_Run;
    return lParent;
}
//===============================================
void GProcessSocketServer_Delete(GProcessO* obj) {
    GProcess_Delete(obj);
}
//===============================================
GProcessO* GProcessSocketServer() {
    if(m_GProcessSocketServerO == 0) {
        m_GProcessSocketServerO = GProcessSocketServer_New();
    }
    return m_GProcessSocketServerO;
}
//===============================================
void GProcessSocketServer_Run(int argc, char** argv) {
    GSocket()->Start(2, 1);
    GSocket()->Status();
    GSocket()->Major();
    GSocket()->Minor();
    GSocket()->MajorMax();
    GSocket()->MinorMax();
    GSocket()->Socket(AF_INET, SOCK_STREAM, 0);
    GSocket()->Address2(AF_INET, INADDR_ANY, 5566);
    GSocket()->Bind();
    GSocket()->Listen();
    while(GSocket()->Accept() == TRUE) {
    	GSocket()->Send();
    	GSocket()->Close2();
    }
    GSocket()->Close();
    GSocket()->Clean();
}
//===============================================
