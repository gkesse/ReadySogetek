//===============================================
#include "GProcess.h"
#include "GProcessMap.h"
#include "GProcessConfig.h"
#include "GProcessSocketServer.h"
#include "GProcessSocketClient.h"
#include "GString.h"
#include "GConfig.h"
//===============================================
GProcessO* GProcess_New() {
    GProcessO* lObj = (GProcessO*)malloc(sizeof(GProcessO));
    lObj->m_child = 0;
    return lObj;
}
//===============================================
void GProcess_Delete(GProcessO* obj) {
    if(obj != 0) {
        if(obj->m_child != 0) {
            free(obj->m_child);
            obj->m_child = 0;
        }
        free(obj);
        obj = 0;
    }
}
//===============================================
GProcessO* GProcess() {
    char* lKey = GConfig()->GetData("PROCESS");
    if(GString()->Is_Equal(lKey, "MAP")) return GProcessMap();
    if(GString()->Is_Equal(lKey, "CONFIG")) return GProcessConfig();
    if(GString()->Is_Equal(lKey, "SOCKET_SERVER")) return GProcessSocketServer();
    if(GString()->Is_Equal(lKey, "SOCKET_CLIENT")) return GProcessSocketClient();
    return GProcessMap();
}
//===============================================
