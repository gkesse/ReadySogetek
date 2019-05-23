//===============================================
#include "GSocket.h"
#include "GString.h"
//===============================================
static GSocketO* m_GSocketO = 0;
//===============================================
void GSocket_Start(const int major, const int minor);
void GSocket_Socket(const int addressFamily, const int type, const int protocol);
void GSocket_Bind(const int addressFamily, const ulong ipAddress, const int port);
void GSocket_Bind2(const int addressFamily, const char* ipAddress, const int port);
void GSocket_Listen();
int GSocket_Accept();
void GSocket_Connect();
void GSocket_Clean();
//===============================================
GSocketO* GSocket_New() {
	GSocketO* lObj = (GSocketO*)malloc(sizeof(GSocketO));
	lObj->m_child = 0;
	lObj->Delete = GSocket_Delete;
	lObj->Start = GSocket_Start;
	lObj->Socket = GSocket_Socket;
	lObj->Bind = GSocket_Bind;
	lObj->Bind2 = GSocket_Bind2;
	lObj->Listen = GSocket_Listen;
	lObj->Accept = GSocket_Accept;
	lObj->Connect = GSocket_Connect;
	lObj->Clean = GSocket_Clean;
	return lObj;
}
//===============================================
void GSocket_Delete() {
	GSocketO* lObj = GSocket();
	if(lObj != 0) {
		if(lObj->m_child != 0) {
			free(lObj->m_child);
			lObj->m_child = 0;
		}
		free(lObj);
		lObj = 0;
	}
}
//===============================================
GSocketO* GSocket() {
	if(m_GSocketO == 0) {
		m_GSocketO = GSocket_New();
	}
	return m_GSocketO;
}
//===============================================
void GSocket_Start(const int major, const int minor) {
	printf("[ SOCKET ] Start...\n");
	WSADATA lWsadata;
	WSAStartup(MAKEWORD(major, major), &lWsadata);
}
//===============================================
void GSocket_Socket(const int addressFamily, const int type, const int protocol) {
	printf("[ SOCKET ] Socket...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	*lSocket = socket(AF_INET, SOCK_STREAM, 0);
}
//===============================================
void GSocket_Bind(const int addressFamily, const ulong ipAddress, const int port) {
	printf("[ SOCKET ] Bind...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	SOCKADDR_IN lSocketAddr;
	lSocketAddr.sin_addr.s_addr = ipAddress;
	lSocketAddr.sin_family = addressFamily;
	lSocketAddr.sin_port = htons(port);
	bind(*lSocket, (SOCKADDR*)&lSocketAddr, sizeof(lSocketAddr));
}
//===============================================
void GSocket_Bind2(const int addressFamily, const char* ipAddress, const int port) {
	printf("[ SOCKET ] Bind...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	SOCKADDR_IN lSocketAddr;
	lSocketAddr.sin_addr.s_addr = inet_addr(ipAddress);
	lSocketAddr.sin_family = addressFamily;
	lSocketAddr.sin_port = htons(port);
	bind(*lSocket, (SOCKADDR*)&lSocketAddr, sizeof(lSocketAddr));
}
//===============================================
void GSocket_Listen() {
	printf("[ SOCKET ] Listen...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	listen(*lSocket, 0);
}
//===============================================
int GSocket_Accept() {
	printf("[ SOCKET ] Accept...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	SOCKADDR_IN lSocketAddr;
	int lSize = sizeof(SOCKADDR);
	int lOk = accept(*lSocket, (SOCKADDR*)&lSocketAddr, &lSize);
	return lOk;
}
//===============================================
void GSocket_Connect() {
	printf("[ SOCKET ] Connect...\n");
}
//===============================================
void GSocket_Clean() {
	printf("[ SOCKET ] Clean...\n");
	WSACleanup();
}
//===============================================
