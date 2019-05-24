//===============================================
#include "GSocketWindows.h"
#include "GString.h"
//===============================================
static GSocketO* m_GSocketWindowsO = 0;
//===============================================
void GSocketWindows_Start(const int major, const int minor);
void GSocketWindows_Socket(const int addressFamily, const int type, const int protocol);
void GSocketWindows_Bind(const int addressFamily, const ulong ipAddress, const int port);
void GSocketWindows_Bind2(const int addressFamily, const char* ipAddress, const int port);
void GSocketWindows_Listen();
int GSocketWindows_Accept();
void GSocketWindows_Connect();
void GSocketWindows_Clean();
//===============================================
GSocketO* GSocketWindows_New() {
	GSocketO* lParent = GSocket_New();
	GSocketWindowsO* lChild = (GSocketWindowsO*)malloc(sizeof(GSocketWindowsO));
	lChild->m_parent = lParent;

	lParent->m_child = lChild;

	lParent->Delete = GSocketWindows_Delete;
	lParent->Start = GSocketWindows_Start;
	lParent->Socket = GSocketWindows_Socket;
	lParent->Bind = GSocketWindows_Bind;
	lParent->Bind2 = GSocketWindows_Bind2;
	lParent->Listen = GSocketWindows_Listen;
	lParent->Accept = GSocketWindows_Accept;
	lParent->Connect = GSocketWindows_Connect;
	lParent->Clean = GSocketWindows_Clean;
	return lParent;
}
//===============================================
void GSocketWindows_Delete(GSocketO* obj) {
	GSocket_Delete(obj);
}
//===============================================
GSocketO* GSocketWindows() {
	if(m_GSocketWindowsO == 0) {
		m_GSocketWindowsO = GSocketWindows_New();
	}
	return m_GSocketWindowsO;
}
//===============================================
void GSocketWindows_Start(const int major, const int minor) {
#if defined(__WIN32)
	printf("[ SOCKET ] Start...\n");
	WSADATA lWsadata;
	WSAStartup(MAKEWORD(major, major), &lWsadata);
#endif
}
//===============================================
void GSocketWindows_Socket(const int addressFamily, const int type, const int protocol) {
#if defined(__WIN32)
	printf("[ SOCKET ] Socket...\n");
	SOCKET* lSocket = &m_GSocketWindowsO->m_socket;
	*lSocket = socket(AF_INET, SOCK_STREAM, 0);
#endif
}
//===============================================
void GSocketWindows_Bind(const int addressFamily, const ulong ipAddress, const int port) {
#if defined(__WIN32)
	printf("[ SOCKET ] Bind...\n");
	SOCKET* lSocket = &m_GSocketWindowsO->m_socket;
	SOCKADDR_IN lSocketAddr;
	lSocketAddr.sin_addr.s_addr = ipAddress;
	lSocketAddr.sin_family = addressFamily;
	lSocketAddr.sin_port = htons(port);
	bind(*lSocket, (SOCKADDR*)&lSocketAddr, sizeof(lSocketAddr));
#endif
}
//===============================================
void GSocketWindows_Bind2(const int addressFamily, const char* ipAddress, const int port) {
#if defined(__WIN32)
	printf("[ SOCKET ] Bind...\n");
	SOCKET* lSocket = &m_GSocketWindowsO->m_socket;
	SOCKADDR_IN lSocketAddr;
	lSocketAddr.sin_addr.s_addr = inet_addr(ipAddress);
	lSocketAddr.sin_family = addressFamily;
	lSocketAddr.sin_port = htons(port);
	bind(*lSocket, (SOCKADDR*)&lSocketAddr, sizeof(lSocketAddr));
#endif
}
//===============================================
void GSocketWindows_Listen() {
#if defined(__WIN32)
	printf("[ SOCKET ] Listen...\n");
	SOCKET* lSocket = &m_GSocketWindowsO->m_socket;
	listen(*lSocket, 0);
#endif
}
//===============================================
int GSocketWindows_Accept() {
#if defined(__WIN32)
	printf("[ SOCKET ] Accept...\n");
	SOCKET* lSocket = &m_GSocketWindowsO->m_socket;
	SOCKADDR_IN lSocketAddr;
	int lSize = sizeof(SOCKADDR);
	int lOk = accept(*lSocket, (SOCKADDR*)&lSocketAddr, &lSize);
	return lOk;
#endif
	return 0;
}
//===============================================
void GSocketWindows_Connect() {
#if defined(__WIN32)
	printf("[ SOCKET ] Connect...\n");
#endif
}
//===============================================
void GSocketWindows_Clean() {
#if defined(__WIN32)
	printf("[ SOCKET ] Clean...\n");
	WSACleanup();
#endif
}
//===============================================
