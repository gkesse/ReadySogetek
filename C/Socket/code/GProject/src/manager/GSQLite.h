//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GSQLiteO GSQLiteO;
typedef struct _GMapO_GSQLite_GCHAR_PTR_GSQLITE_PTR GMapO_GSQLite_GCHAR_PTR_GSQLITE_PTR;
//===============================================
struct _GSQLiteO {
    void (*Delete)();
    void (*Version)();
    void (*Open)(char* dbName, const char* path);
    void (*Close)(char* dbName);
    GMapO(GSQLite_GCHAR_PTR_GSQLITE_PTR)* m_dbMap;
};
//===============================================
GSQLiteO* GSQLite_New();
void GSQLite_Delete();
GSQLiteO* GSQLite();
//===============================================
#endif
//===============================================
