//===============================================
#ifndef _GConfig_
#define _GConfig_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GConfigO GConfigO;
//===============================================
struct _GConfigO {
    void* m_child;
    void (*Delete)();
    void (*Set_Data)(char* key, char* value);
    char* (*Get_Data)(char* key);
    void (*Show)();
    void (*Clear)();
    void (*Remove)(char* key);
};
//===============================================
GConfigO* GConfig_New();
void GConfig_Delete();
GConfigO* GConfig();
//===============================================
#endif
//===============================================
