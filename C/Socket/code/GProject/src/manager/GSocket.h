//===============================================
#ifndef _GSocket_
#define _GSocket_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GSocketO GSocketO;
//===============================================
struct _GSocketO {
    void* m_child;
    void (*Delete)();
    void (*Start)();
    void (*Socket)();
    void (*Bind)();
    void (*Listen)();
    void (*Accept)();
    void (*Connect)();
    void (*Clean)();

    SOCKET m_socket;
};
//===============================================
GSocketO* GSocket_New();
void GSocket_Delete();
GSocketO* GSocket();
//===============================================
#endif
//===============================================
