//===============================================
#include "GMap.h"
#include "GString.h"
//===============================================
static void GMap_SetData(GMapO* obj, const char* key, const char* value);
static void GMap_Clear(GMapO* obj);
static void GMap_Remove(GMapO* obj, const char* key);
static void GMap_Size(GMapO* obj);
static void GMap_Show(GMapO* obj);
//===============================================
static void GMap_RemoveNode(GMapNodeO* node);
//===============================================
GMapO* GMap_New() {
	GMapO* lObj = (GMapO*)malloc(sizeof(GMapO));

	lObj->Delete = GMap_Delete;
	lObj->SetData = GMap_SetData;
	lObj->Clear = GMap_Clear;
	lObj->Remove = GMap_Remove;
	lObj->Show = GMap_Show;
	lObj->Size = GMap_Size;
	lObj->m_head = 0;
	return lObj;
}
//===============================================
void GMap_Delete(GMapO* obj) {
	if(obj != 0) {
		obj->Clear(obj);
		free(obj);
		obj = 0;
	}
}
//===============================================
static void GMap_SetData(GMapO* obj, const char* key, const char* value) {
	GMapNodeO* lLast = obj->m_head;
	GMapNodeO* lNext = lLast;
	while(lNext != 0) {
		lLast = lNext;
		int lStrcmp = strcmp(lLast->m_key, key);
		if(lStrcmp == 0) {
			free(lLast->m_value);
			int lValue = strlen(value) + 1;
			lLast->m_value = (char*)malloc(sizeof(char)*lValue);
			sprintf(lLast->m_value, "%s", value);
			return;
		}
		lNext = lNext->m_next;
	}

	GMapNodeO* lNode = (GMapNodeO*)malloc(sizeof(GMapNodeO));
	int lKey = strlen(key) + 1;
	int lValue = strlen(value) + 1;
	lNode->m_key = (char*)malloc(sizeof(char)*lKey);
	lNode->m_value = (char*)malloc(sizeof(char)*lValue);
	sprintf(lNode->m_key, "%s", key);
	sprintf(lNode->m_value, "%s", value);
	lNode->m_next = 0;

	if(lLast == 0) obj->m_head = lNode;
	else lLast->m_next = lNode;
}
//===============================================
static void GMap_Clear(GMapO* obj) {
	GMapNodeO* lNext = obj->m_head;
	while(lNext != 0) {
		GMapNodeO* lLast = lNext;
		lNext = lNext->m_next;
		GMap_RemoveNode(lLast);
	}
	obj->m_head = 0;
}
//===============================================
static void GMap_Remove(GMapO* obj, const char* key) {
	GMapNodeO* lNode = obj->m_head;
	GMapNodeO* lPrevious = 0;
	while(lNode != 0) {

		int lStrcmp = strcmp(lNode->m_key, key);
		if(lStrcmp == 0) {
			if(lPrevious != 0) lPrevious->m_next = lNode->m_next;
			else obj->m_head = lNode->m_next;
			GMap_RemoveNode(lNode);
			return;
		}
		lPrevious = lNode;
		lNode = lNode->m_next;
	}
}
//===============================================
static void GMap_Size(GMapO* obj) {
	GMapNodeO* lNext = obj->m_head;
	int lSize = 0;

	while(lNext != 0) {
		lSize++;
		lNext = lNext->m_next;
	}
	printf("[ SIZE ] : %d...\n", lSize);
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
static void GMap_RemoveNode(GMapNodeO* node) {
	if(node != 0) {
		if(node->m_key != 0) {
			free(node->m_key);
			node->m_key = 0;
		}
		if(node->m_value != 0) {
			free(node->m_value);
			node->m_value = 0;
		}
		free(node);
		node = 0;
	}
}
//===============================================
