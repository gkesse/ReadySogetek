//===============================================
#include "GMap.h"
#include "GString.h"
//===============================================
static void GMap_SetData(GMapO* obj, const char* key, const char* value);
static void GMap_Show(GMapO* obj);
//===============================================
GMapO* GMap_New() {
	GMapO* lObj = (GMapO*)malloc(sizeof(GMapO));

	lObj->Delete = GMap_Delete;
	lObj->SetData = GMap_SetData;
	lObj->Show = GMap_Show;
	lObj->m_head = 0;
	return lObj;
}
//===============================================
void GMap_Delete(GMapO* obj) {

}
//===============================================
static void GMap_SetData(GMapO* obj, const char* key, const char* value) {
	GMapNodeO* lHead = obj->m_head;
	if(lHead == 0) {
		GMapNodeO* lNode = (GMapNodeO*)malloc(sizeof(GMapNodeO));
		int lKey = strlen(key) + 1;
		int lValue = strlen(value) + 1;
		lNode->m_key = (char*)malloc(sizeof(char)*lKey);
		lNode->m_value = (char*)malloc(sizeof(char)*lValue);
		sprintf(lNode->m_key, "%s", key);
		sprintf(lNode->m_value, "%s", value);
		lNode->m_next = 0;
		obj->m_head = lNode;
	}
	lHead = obj->m_head;
	printf("[ MAP ] : %s = %s\n", lHead->m_key, lHead->m_value);
}
//===============================================
static void GMap_Show(GMapO* obj) {
	GMapNodeO* lNode = obj->m_head;

	while(lNode != 0) {
		char* lKey = lNode->m_key;
		char* lValue = lNode->m_value;
		printf("%s = %s\n", lKey, lValue);
		lNode = lNode->m_next;
	}
	printf("\n");
}
//===============================================
