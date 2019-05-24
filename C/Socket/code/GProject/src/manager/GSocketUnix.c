//===============================================
#include "GSocketUnix.h"
#include "GString.h"
//===============================================
static GSocketO* m_GSocketUnixO = 0;
//===============================================
void GSocketUnix_Start(const int major, const int minor);
void GSocketUnix_Socket(const int addressFamily, const int type, const int protocol);
void GSocketUnix_Bind(const int addressFamily, const ulong ipAddress, const int port);
void GSocketUnix_Bind2(const int addressFamily, const char* ipAddress, const int port);
void GSocketUnix_Listen();
int GSocketUnix_Accept();
void GSocketUnix_Connect();
void GSocketUnix_Clean();
//===============================================
GSocketO* GSocketUnix_New() {
	GSocketO* lParent = GSocket_New();
	GSocketUnixO* lChild = (GSocketUnixO*)malloc(sizeof(GSocketUnixO));
	lChild->m_parent = lParent;

	lParent->m_child = lChild;

	lParent->Delete = GSocketUnix_Delete;
	lParent->Start = GSocketUnix_Start;
	lParent->Socket = GSocketUnix_Socket;
	lParent->Bind = GSocketUnix_Bind;
	lParent->Bind2 = GSocketUnix_Bind2;
	lParent->Listen = GSocketUnix_Listen;
	lParent->Accept = GSocketUnix_Accept;
	lParent->Connect = GSocketUnix_Connect;
	lParent->Clean = GSocketUnix_Clean;
	return lParent;
}
//===============================================
void GSocketUnix_Delete(GSocketO* obj) {
	GSocket_Delete(obj);
}
//===============================================
GSocketO* GSocketUnix() {
	if(m_GSocketUnixO == 0) {
		m_GSocketUnixO = GSocketUnix_New();
	}
	return m_GSocketUnixO;
}
//===============================================
void GSocketUnix_Start(const int major, const int minor) {
#ifndef __WIN32
	printf("[ SOCKET ] Start...\n");
#endif
}
//===============================================
void GSocketUnix_Socket(const int addressFamily, const int type, const int protocol) {
	printf("[ SOCKET ] Socket...\n");
}
//===============================================
void GSocketUnix_Bind(const int addressFamily, const ulong ipAddress, const int port) {
#ifndef __WIN32
	printf("[ SOCKET ] Bind...\n");
#endif
}
//===============================================
void GSocketUnix_Bind2(const int addressFamily, const char* ipAddress, const int port) {
#ifndef __WIN32
	printf("[ SOCKET ] Bind...\n");
#endif
}
//===============================================
void GSocketUnix_Listen() {
#ifndef __WIN32
	printf("[ SOCKET ] Listen...\n");
#endif
}
//===============================================
int GSocketUnix_Accept() {
#ifndef __WIN32
	printf("[ SOCKET ] Accept...\n");
#endif
	return 0;
}
//===============================================
void GSocketUnix_Connect() {
#ifndef __WIN32
	printf("[ SOCKET ] Connect...\n");
#endif
}
//===============================================
void GSocketUnix_Clean() {
#ifndef __WIN32
	printf("[ SOCKET ] Clean...\n");
#endif
}
//===============================================
