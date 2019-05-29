//===============================================
#include "GSQLite.h"
#include "GConsole.h"
//===============================================
typedef char* GCHAR_PTR;
typedef sqlite3* GSQLITE_PTR;
typedef sqlite3_stmt* GSQLITE_STMT_PTR;
//===============================================
GDECLARE_MAP(GCHAR_PTR, GSQLITE_PTR, GSQLite_GCHAR_PTR_GSQLITE_PTR)
GDEFINE_MAP(GCHAR_PTR, GSQLITE_PTR, GSQLite_GCHAR_PTR_GSQLITE_PTR)
GDECLARE_MAP(GCHAR_PTR, GSQLITE_STMT_PTR, GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)
GDEFINE_MAP(GCHAR_PTR, GSQLITE_STMT_PTR, GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)
//===============================================
static GSQLiteO* m_GSQLiteO = 0;
//===============================================
void GSQLite_Version();
void GSQLite_Open(char* dbName, const char* path);
void GSQLite_Close(char* dbName);
//===============================================
int GSQLite_MapEqual(char* key1, char* key2);
//===============================================
GSQLiteO* GSQLite_New() {
    GSQLiteO* lObj = (GSQLiteO*)malloc(sizeof(GSQLiteO));
    lObj->Delete = GSQLite_Delete;
    lObj->Version = GSQLite_Version;
    lObj->Open = GSQLite_Open;
    lObj->Close = GSQLite_Close;
	lObj->m_dbMap = GMap_New_GSQLite_GCHAR_PTR_GSQLITE_PTR();
    return lObj;
}
//===============================================
void GSQLite_Delete() {
    GSQLiteO* lObj = GSQLite();
    if(lObj != 0) {
        free(lObj);
        lObj = 0;
    }
}
//===============================================
GSQLiteO* GSQLite() {
    if(m_GSQLiteO == 0) {
        m_GSQLiteO = GSQLite_New();
    }
    return m_GSQLiteO;
}
//===============================================
void GSQLite_Version() {
	const char* lVersion = sqlite3_libversion();
	GConsole()->Print("[ SQLITE ] Version: %s\n", lVersion);
}
//===============================================
void GSQLite_Open(char* dbName, const char* path) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb;
	int lOk = sqlite3_open(path, &lDb);
	if(lOk == SQLITE_OK) GConsole()->Print("[ SQLITE ] Open is OK...\n");
	lDbMap->SetData(lDbMap, dbName, lDb, GSQLite_MapEqual);
}
//===============================================
void GSQLite_PrepareV2(char* dbName, const char* sql) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* lStmtMap = m_GSQLiteO->m_stmtMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	sqlite3_stmt* lStmt;
	sqlite3_prepare_v2(lDb, sql, -1, &lStmt, 0);
	lStmtMap->SetData(lStmtMap, dbName, lStmt, GSQLite_MapEqual);
}
//===============================================
int GSQLite_Step(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* lStmtMap = m_GSQLiteO->m_stmtMap;
	sqlite3_stmt* lStmt = lStmtMap->GetData(lStmtMap, dbName, GSQLite_MapEqual, 0);;
	int lOk = sqlite3_step(lStmt);
	return lOk;
}
//===============================================
const uchar* GSQLite_ColumnText(char* dbName, const int index) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* lStmtMap = m_GSQLiteO->m_stmtMap;
	sqlite3_stmt* lStmt = lStmtMap->GetData(lStmtMap, dbName, GSQLite_MapEqual, 0);;
	const uchar* lText = sqlite3_column_text(lStmt, index);
	GConsole()->Print("[ SQLITE ] ColumnText: %s\n", lText);
	return lText;
}
//===============================================
void GSQLite_Error(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	const char* lError = sqlite3_errmsg(lDb);
	GConsole()->Print("[ SQLITE ] Error: %s\n", lError);
}
//===============================================
void GSQLite_Close(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	int lOk = sqlite3_close(lDb);
	if(lOk == SQLITE_OK) GConsole()->Print("[ SQLITE ] Close is OK...\n");
}
//===============================================
int GSQLite_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
//===============================================
