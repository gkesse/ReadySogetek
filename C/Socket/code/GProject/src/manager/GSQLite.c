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
static void GSQLite_Version();
static void GSQLite_Open(char* dbName, const char* path);
static void GSQLite_Close(char* dbName);
//===============================================
static int GSQLite_MapEqual(char* key1, char* key2);
//===============================================
GSQLiteO* GSQLite_New() {
    GSQLiteO* lObj = (GSQLiteO*)malloc(sizeof(GSQLiteO));
    lObj->Delete = GSQLite_Delete;
    lObj->Version = GSQLite_Version;
    lObj->Open = GSQLite_Open;
    lObj->Close = GSQLite_Close;
	lObj->m_dbMap = GMap_New_GSQLite_GCHAR_PTR_GSQLITE_PTR();
	lObj->m_error = 0;
	lObj->m_lastId = -1;
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
static void GSQLite_Version() {
	const char* lVersion = sqlite3_libversion();
	GConsole()->Print("[ SQLITE ] Version: %s\n", lVersion);
}
//===============================================
static void GSQLite_Open(char* dbName, const char* path) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb;
	int lOk = sqlite3_open(path, &lDb);
	if(lOk != SQLITE_OK) {GConsole()->Print("[ SQLITE ] [ ERROR ] Open\n"); exit(1);}
	lDbMap->SetData(lDbMap, dbName, lDb, GSQLite_MapEqual);
}
//===============================================
static void GSQLite_Exec(char* dbName, const char* sql) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	char** lError = &m_GSQLiteO->m_error;
	int lOk = sqlite3_exec(lDb, sql, 0, 0, lError);
	if(lOk != SQLITE_OK) {GConsole()->Print("[ SQLITE ] [ ERROR ] Exec: %s\n", *lError); exit(1);}
}
//===============================================
int GSQLite_LastId(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	int lLastId = sqlite3_last_insert_rowid(lDb);
	return lLastId;
}
//===============================================
static void GSQLite_PrepareV2(char* dbName, const char* sql) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* lStmtMap = m_GSQLiteO->m_stmtMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	sqlite3_stmt* lStmt;
	int lOk = sqlite3_prepare_v2(lDb, sql, -1, &lStmt, 0);
	if(lOk != SQLITE_OK) {GConsole()->Print("[ SQLITE ] [ ERROR ] PrepareV2: %s\n", sqlite3_errmsg(lDb)); exit(1); }
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
static void GSQLite_Error(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	const char* lError = sqlite3_errmsg(lDb);
	GConsole()->Print("[ SQLITE ] Error: %s\n", lError);
}
//===============================================
static void GSQLite_Free() {
	char* lError = m_GSQLiteO->m_error;
	sqlite3_free(lError);
}
//===============================================
static void GSQLite_Finalize(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* lStmtMap = m_GSQLiteO->m_stmtMap;
	sqlite3_stmt* lStmt = lStmtMap->GetData(lStmtMap, dbName, GSQLite_MapEqual, 0);;
	sqlite3_finalize(lStmt);
}
//===============================================
static void GSQLite_Close(char* dbName) {
	GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* lDbMap = m_GSQLiteO->m_dbMap;
	sqlite3* lDb = lDbMap->GetData(lDbMap, dbName, GSQLite_MapEqual, 0);
	int lOk = sqlite3_close(lDb);
	if(lOk == SQLITE_OK) GConsole()->Print("[ SQLITE ] Close is OK...\n");
}
//===============================================
static int GSQLite_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
//===============================================
