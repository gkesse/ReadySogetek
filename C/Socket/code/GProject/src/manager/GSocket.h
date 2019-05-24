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
    void (*Delete)(GSocketO* obj);
    void (*Start)(const int major, const int minor);
    void (*Socket)(const int addressFamily, const int type, const int protocol);
    void (*Bind)(const int addressFamily, const ulong ipAddress, const int port);
    void (*Bind2)(const int addressFamily, const char* ipAddress, const int port);
    void (*Listen)();
    int (*Accept)();
    void (*Connect)();
#if defined(__WIN32)
    int (*Send)(SOCKET socket, const char* buffer, const int length, const int flags);
#endif
    void (*Read)();
    void (*Close)();
    void (*Clean)();
#if defined(__WIN32)
    SOCKET m_socket;
#endif
};
//===============================================
GSocketO* GSocket_New();
void GSocket_Delete(GSocketO* obj);
GSocketO* GSocket();
//===============================================
#endif
//===============================================
