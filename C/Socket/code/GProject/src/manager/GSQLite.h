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
typedef int (*GSQLITE_CALLBACK)(void* unused, int rows, char** values, char** fields);
//===============================================
struct _GSQLiteO {
    void (*Delete)();
    void (*Version)();
    void (*Open)(char* dbName, const char* path);
    void (*Exec)(char* dbName, GSQLITE_CALLBACK callback, const char* sql);
    int (*LastId)(char* dbName);
    void (*PrepareV2)(char* dbName, const char* sql);
    void (*BindInt)(char* dbName, const char* sql, const int index, const int value);
    void (*BindParameterIndexInt)(char* dbName, const char* parameterIndex, const int value);
    int (*Step)(char* dbName);
    void (*BindBold)(char* dbName, const int index, const void* data, const int size);
    const uchar* (*ColumnText)(char* dbName, const int index);
    int (*ColumnBytes)(char* dbName, const int index);
    const void* (*ColumnBold)(char* dbName, const int index);
    void (*GetAutocommit)(char* dbName);
    void (*Error)(char* dbName);
    void (*Free)();
    void (*Finalize)(char* dbName);
    void (*Close)(char* dbName);
    //===============================================
    void (*ShowTables)(char* dbName);
    //===============================================
    GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* m_dbMap;
    GMapO(GSQLite_GCHAR_PTR_GSQLITE_STMT_PTR)* m_stmtMap;
    char* m_error;
    int m_lastId;
    int m_bytes;
};
//===============================================
GSQLiteO* GSQLite_New();
void GSQLite_Delete();
GSQLiteO* GSQLite();
//===============================================
#endif
//===============================================
