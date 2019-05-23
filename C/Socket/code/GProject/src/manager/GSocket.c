//===============================================
#include "GSocket.h"
//===============================================
static GSocketO* m_GSocketO = 0;
//===============================================
void GSocket_Start();
void GSocket_Socket();
void GSocket_Bind();
void GSocket_Listen();
void GSocket_Accept();
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
void GSocket_Start(const char* version) {
	printf("[ SOCKET ] Start...\n");
	WSADATA lWsadata;
	WSAStartup(MAKEWORD(2,0), &lWsadata);
}
//===============================================
void GSocket_Socket() {
	printf("[ SOCKET ] Socket...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	*lSocket = socket(AF_INET, SOCK_STREAM, 0);
}
//===============================================
void GSocket_Bind() {
	printf("[ SOCKET ] Bind...\n");
	SOCKET* lSocket = &m_GSocketO->m_socket;
	SOCKADDR_IN lSocketAddr;
	lSocketAddr.sin_addr.s_addr = INADDR_ANY;
	lSocketAddr.sin_family = AF_INET;
	lSocketAddr.sin_port = htons(23);
	bind(*lSocket, (SOCKADDR*)&lSocketAddr, sizeof(lSocketAddr));
}
//===============================================
void GSocket_Listen() {
	printf("[ SOCKET ] Listen...\n");
}
//===============================================
void GSocket_Accept() {
	printf("[ SOCKET ] Accept...\n");
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
