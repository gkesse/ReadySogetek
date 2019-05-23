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
    void (*Start)(const int major, const int minor);
    void (*Socket)(const int addressFamily, const int type, const int protocol);
    void (*Bind)(const int addressFamily, const ulong ipAddress, const int port);
    void (*Bind2)(const int addressFamily, const char* ipAddress, const int port);
    void (*Listen)();
    int (*Accept)();
    void (*Connect)();
    int (*Send)(SOCKET socket, const char* buffer, const int length, const int flags);
    void (*Read)();
    void (*Close)();
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
