//===============================================
#include "GConfigTemplate.h"
//===============================================
typedef char* GCHAR_PTR;
//===============================================
GDECLARE_MAP(GCHAR_PTR, GCHAR_PTR, GConfigTemplate_GCHAR_PTR_GCHAR_PTR)
GDEFINE_MAP(GCHAR_PTR, GCHAR_PTR, GConfigTemplate_GCHAR_PTR_GCHAR_PTR)
//===============================================
static GConfigO* m_GConfigTemplateO = 0;
//===============================================
void GConfigTemplate_Clear();
void GConfigTemplate_Remove(char* key);
void GConfigTemplate_SetData(char* key, char* value);
char* GConfigTemplate_GetData(char* key);
void GConfigTemplate_Show();
//===============================================
int GConfigTemplate_MapEqual(char* str1, char* str2);
void GConfigTemplate_MapShow(char* key, char* value);
//===============================================
GConfigO* GConfigTemplate_New() {
	GConfigO* lParent = GConfig_New();
	GConfigTemplateO* lChild = (GConfigTemplateO*)malloc(sizeof(GConfigTemplateO));

	lChild->m_parent = lParent;
	lChild->m_dataMap = GMap_New_GConfigTemplate_GCHAR_PTR_GCHAR_PTR();

	lParent->m_child = lChild;
	lParent->Delete = GConfigTemplate_Delete;
	lParent->SetData = GConfigTemplate_SetData;
	lParent->GetData = GConfigTemplate_GetData;
	lParent->Show = GConfigTemplate_Show;
	lParent->Clear = GConfigTemplate_Clear;
	lParent->Remove = GConfigTemplate_Remove;
	return lParent;
}
//===============================================
void GConfigTemplate_Delete() {
	GConfigTemplate_Clear();
	GConfig_Delete();
}
//===============================================
GConfigO* GConfigTemplate() {
	if(m_GConfigTemplateO == 0) {
		m_GConfigTemplateO = GConfigTemplate_New();
	}
	return m_GConfigTemplateO;
}
//===============================================
void GConfigTemplate_Clear() {
	GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
	GMapO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
	lDataMap->Clear(lDataMap);
}
//===============================================
void GConfigTemplate_Remove(char* key) {
	GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
	GMapO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
	lDataMap->Remove(lDataMap, key, GConfigTemplate_MapEqual);
}
//===============================================
void GConfigTemplate_SetData(char* key, char* value) {
	GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
	GMapO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
	lDataMap->SetData(lDataMap, key, value);
}
//===============================================
char* GConfigTemplate_GetData(char* key) {
	GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
	GMapO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
	lDataMap->GetData(lDataMap, key, GConfigTemplate_MapEqual, 0);
}
//===============================================
void GConfigTemplate_Show() {
	GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
	GMapO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
	GMapNodeO(GConfigTemplate_GCHAR_PTR_GCHAR_PTR)* lNext = lDataMap->m_head;
	while(lNext != 0) {
		char* lKey = lNext->m_key;
		char* lValue = lNext->m_value;
		lNext = lNext->m_next;
	}
	printf("\n");
}
//===============================================
int GConfigTemplate_MapEqual(char* str1, char* str2) {
	int lStrcmp = strcmp(str1, str2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
//===============================================
void GConfigTemplate_MapShow(char* key, char* value) {
	printf("%s = %s\n", key, value);
}
//===============================================
