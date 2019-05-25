//===============================================
#include "GSocketWindows.h"
#include "GString.h"
//===============================================
static GSocketO* m_GSocketWindowsO = 0;
//===============================================
void GSocketWindows_Start(const int major, const int minor);
void GSocketWindows_Status();
void GSocketWindows_Major();
void GSocketWindows_Minor();
void GSocketWindows_MajorMax();
void GSocketWindows_MinorMax();
void GSocketWindows_Socket(const int addressFamily, const int type, const int protocol);
void GSocketWindows_SocketName();
void GSocketWindows_IpAddress();
void GSocketWindows_Port();
void GSocketWindows_Address(const int addressFamily, const char* ipAddress, const int port);
void GSocketWindows_Address2(const int addressFamily, const ulong ipAddress, const int port);
void GSocketWindows_Bind();
void GSocketWindows_Listen(const int backlog);
int GSocketWindows_Accept();
void GSocketWindows_Connect();
void GSocketWindows_Send();
void GSocketWindows_Recv();
void GSocketWindows_Close();
void GSocketWindows_Close2();
void GSocketWindows_Clean();
//===============================================
GSocketO* GSocketWindows_New() {
	GSocketO* lParent = GSocket_New();
	GSocketWindowsO* lChild = (GSocketWindowsO*)malloc(sizeof(GSocketWindowsO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GSocketWindows_Delete;
	lParent->Start = GSocketWindows_Start;
	lParent->Status = GSocketWindows_Status;
	lParent->Major = GSocketWindows_Major;
	lParent->Minor = GSocketWindows_Minor;
	lParent->MajorMax = GSocketWindows_MajorMax;
	lParent->MinorMax = GSocketWindows_MinorMax;
	lParent->Socket = GSocketWindows_Socket;
	lParent->SocketName = GSocketWindows_SocketName;
	lParent->IpAddress = GSocketWindows_IpAddress;
	lParent->Port = GSocketWindows_Port;
	lParent->Address = GSocketWindows_Address;
	lParent->Address2 = GSocketWindows_Address2;
	lParent->Bind = GSocketWindows_Bind;
	lParent->Listen = GSocketWindows_Listen;
	lParent->Accept = GSocketWindows_Accept;
	lParent->Connect = GSocketWindows_Connect;
	lParent->Send = GSocketWindows_Send;
	lParent->Recv = GSocketWindows_Recv;
	lParent->Close = GSocketWindows_Close;
	lParent->Close2 = GSocketWindows_Close2;
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
	printf("[ SOCKET ] Start %d.%d...\n", major, minor);
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	WSAStartup(MAKEWORD(major, minor), lWsaData);
#endif
}
//===============================================
void GSocketWindows_Status() {
#if defined(__WIN32)
	printf("[ SOCKET ] Status...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	char* lStatus = lWsaData->szSystemStatus;
	printf("[ STATUS ] %s...\n", lStatus);
#endif
}
//===============================================
void GSocketWindows_Major() {
#if defined(__WIN32)
	printf("[ SOCKET ] Major...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	int lMajor = LOBYTE(lWsaData->wVersion);
	printf("[ MAJOR ] %d...\n", lMajor);
#endif
}
//===============================================
void GSocketWindows_Minor() {
#if defined(__WIN32)
	printf("[ SOCKET ] Minor...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	int lMinor = HIBYTE(lWsaData->wVersion);
	printf("[ MINOR ] %d...\n", lMinor);
#endif
}
//===============================================
void GSocketWindows_MajorMax() {
#if defined(__WIN32)
	printf("[ SOCKET ] MajorMax...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	int lMajor = LOBYTE(lWsaData->wHighVersion);
	printf("[ MAJOR MAX ] %d...\n", lMajor);
#endif
}
//===============================================
void GSocketWindows_MinorMax() {
#if defined(__WIN32)
	printf("[ SOCKET ] MinorMax...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	WSADATA* lWsaData = &lSocketWindows->m_wsaData;
	int lMinor = HIBYTE(lWsaData->wHighVersion);
	printf("[ MINOR MAX ] %d...\n", lMinor);
#endif
}
//===============================================
void GSocketWindows_Socket(const int addressFamily, const int type, const int protocol) {
#if defined(__WIN32)
	printf("[ SOCKET ] Socket...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	*lSocket = socket(addressFamily, type, protocol);
#endif
}
//===============================================
void GSocketWindows_SocketName() {
#if defined(__WIN32)
	printf("[ SOCKET ] SocketName...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	int lSize = sizeof(*lAddress);
	getsockname(*lSocket, (SOCKADDR*)lAddress, &lSize);
#endif
}
//===============================================
void GSocketWindows_IpAddress() {
#if defined(__WIN32)
	printf("[ SOCKET ] IpAddress...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	char* lIpAddress = inet_ntoa(lAddress->sin_addr);
	printf("[ IP_ADDRESS ] %s...\n", lIpAddress);
#endif
}
//===============================================
void GSocketWindows_Port() {
#if defined(__WIN32)
	printf("[ SOCKET ] Port...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	int lPort = htons(lAddress->sin_port);
	printf("[ PORT ] %d...\n", lPort);
#endif
}
//===============================================
void GSocketWindows_Address(const int addressFamily, const char* ipAddress, const int port) {
#if defined(__WIN32)
	printf("[ SOCKET ] Address...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	lAddress->sin_addr.s_addr = inet_addr(ipAddress);
	lAddress->sin_family = addressFamily;
	lAddress->sin_port = htons(port);
#endif
}
//===============================================
void GSocketWindows_Address2(const int addressFamily, const ulong ipAddress, const int port) {
#if defined(__WIN32)
	printf("[ SOCKET ] Address2...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	lAddress->sin_addr.s_addr = htonl(ipAddress);
	lAddress->sin_family = addressFamily;
	lAddress->sin_port = htons(port);
#endif
}
//===============================================
void GSocketWindows_Bind() {
#if defined(__WIN32)
	printf("[ SOCKET ] Bind...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	int lSize = sizeof(*lAddress);
	bind(*lSocket, (SOCKADDR*)lAddress, lSize);
#endif
}
//===============================================
void GSocketWindows_Listen(const int backlog) {
#if defined(__WIN32)
	printf("[ SOCKET ] Listen...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	listen(*lSocket, backlog);
#endif
}
//===============================================
int GSocketWindows_Accept() {
#if defined(__WIN32)
	printf("[ SOCKET ] Accept...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	SOCKET* lSocket2 = &lSocketWindows->m_socket2;
	SOCKADDR_IN* lAddress2 = &lSocketWindows->m_address2;
	int lSize2 = sizeof(*lAddress2);
	*lSocket2 = accept(*lSocket, (SOCKADDR*)lAddress2, &lSize2);
	int lOk = (*lSocket2 != INVALID_SOCKET) ? TRUE : FALSE;
	return lOk;
#endif
	return 0;
}
//===============================================
void GSocketWindows_Connect() {
#if defined(__WIN32)
	printf("[ SOCKET ] Connect...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	SOCKADDR_IN* lAddress = &lSocketWindows->m_address;
	int lSize = sizeof(*lAddress);
	connect(*lSocket, (SOCKADDR*)lAddress, lSize);
#endif
}
//===============================================
void GSocketWindows_Send() {
#if defined(__WIN32)
	printf("[ SOCKET ] Send...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket2 = &lSocketWindows->m_socket2;
	char* lBuffer = "Bonjour tout le monde";
	int lSize = strlen(lBuffer) + 1;
	printf("[ SEND ] %s...\n", lBuffer);
	send(*lSocket2, lBuffer, lSize, 0);
#endif
}
//===============================================
void GSocketWindows_Recv() {
#if defined(__WIN32)
	printf("[ SOCKET ] Recv...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	char lBuffer[255];
	int lSize = sizeof(lBuffer);
	recv(*lSocket, lBuffer, lSize, 0);
	printf("[ RECV ] %s...\n", lBuffer);
#endif
}
//===============================================
void GSocketWindows_Close() {
#if defined(__WIN32)
	printf("[ SOCKET ] Close...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket = &lSocketWindows->m_socket;
	closesocket(*lSocket);
#endif
}
//===============================================
void GSocketWindows_Close2() {
#if defined(__WIN32)
	printf("[ SOCKET ] Close2...\n");
	GSocketWindowsO* lSocketWindows = m_GSocketWindowsO->m_child;
	SOCKET* lSocket2 = &lSocketWindows->m_socket2;
	closesocket(*lSocket2);
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
