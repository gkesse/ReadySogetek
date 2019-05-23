//===============================================
#include "GProcess.h"
#include "GProcessExo3.h"
#include "GProcessExo4.h"
#include "GProcessExo5.h"
#include "GProcessExo6.h"
#include "GProcessExo49.h"
#include "GProcessExo50.h"
#include "GProcessExo51.h"
#include "GProcessExo52.h"
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
    char* lKey = GConfig()->Get_Data("PROCESS");
    if(GString()->Is_Equal(lKey, "Exo3")) return GProcessExo3();
    if(GString()->Is_Equal(lKey, "Exo4")) return GProcessExo4();
    if(GString()->Is_Equal(lKey, "Exo5")) return GProcessExo5();
    if(GString()->Is_Equal(lKey, "Exo6")) return GProcessExo6();
    if(GString()->Is_Equal(lKey, "Exo49")) return GProcessExo49();
    if(GString()->Is_Equal(lKey, "Exo50")) return GProcessExo50();
    if(GString()->Is_Equal(lKey, "Exo51")) return GProcessExo51();
    if(GString()->Is_Equal(lKey, "Exo52")) return GProcessExo52();
    return GProcessExo4();
}
//===============================================
