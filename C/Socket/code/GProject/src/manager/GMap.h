//===============================================
#ifndef _GMap_
#define _GMap_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GMapNodeO GMapNodeO;
typedef struct _GMapO GMapO;
//===============================================
struct _GMapNodeO {
	char* m_key;
    char* m_value;
    GMapNodeO* m_next;
};
//===============================================
struct _GMapO {
    void (*Delete)(GMapO* obj);
    void (*SetData)(GMapO* obj, const char* key, const char* value);
    void (*Clear)(GMapO* obj);
    void (*Remove)(GMapO* obj, const char* key);
    void (*Size)(GMapO* obj);
    void (*Show)(GMapO* obj);
    GMapNodeO* m_head;
};
//===============================================
GMapO* GMap_New();
void GMap_Delete(GMapO* obj);
//===============================================
#endif
//===============================================
