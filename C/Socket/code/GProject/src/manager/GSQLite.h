//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GSQLiteO GSQLiteO;
typedef struct _GMapO_GSQLite_GCHAR_PTR_GSQLITE_PTR GMapO_GSQLite_GCHAR_PTR_GSQLITE_PTR;
typedef struct _GMapO_GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR GMapO_GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR;
typedef int (*GSQLITE_CALLBACK)(void *unused, int count, char **data, char **columns);
//===============================================
struct _GSQLiteO {
    void (*Delete)();
    void (*Version)();
    void (*Open)(char* dbName, const char* path);
    void (*Close)(char* dbName);
    GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* m_dbMap;
    GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* m_stmtMap;
    char* m_error;
    int m_lastId;
};
//===============================================
GSQLiteO* GSQLite_New();
void GSQLite_Delete();
GSQLiteO* GSQLite();
//===============================================
#endif
//===============================================
