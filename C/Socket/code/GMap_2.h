//===============================================
#ifndef _GMap_
#define _GMap_
//===============================================
#include "GInclude.h"
//===============================================
#define GDECLARE_MAP(GKEY, GVALUE) \
		\
		typedef struct _GMapNodeO_##GKEY_##GVALUE GMapNodeO_##GKEY_##GVALUE; \
		typedef struct _GMapO_##GKEY_##GVALUE GMapO_##GKEY_##GVALUE; \
		\
		struct _GMapNodeO_##GKEY_##GVALUE { \
			GKEY m_key; \
			GVALUE m_value; \
			GMapNodeO_##GKEY_##GVALUE* m_next; \
		}; \
		\
		struct _GMapO_##GKEY_##GVALUE { \
			void (*Delete)(GMapO_##GKEY_##GVALUE* obj); \
			void (*SetData)(GMapO_##GKEY_##GVALUE* obj, const GKEY key, const GVALUE value); \
			void (*Clear)(GMapO_##GKEY_##GVALUE* obj); \
			void (*Remove)(GMapO_##GKEY_##GVALUE* obj, const GKEY key); \
			void (*Size)(GMapO_##GKEY_##GVALUE* obj); \
			void (*Show)(GMapO_##GKEY_##GVALUE* obj); \
			GMapNodeO_##GKEY_##GVALUE* m_head; \
		}; \
		\
		GMapO_##GKEY_##GVALUE* GMap_New(); \
		void GMap_Delete(GMapO_##GKEY_##GVALUE* obj);
//===============================================
#define GDEFINE_MAP(GKEY, GVALUE) \
		\
		void GMap_SetData(GMapO_##GKEY_##GVALUE* obj, const GKEY key, const GVALUE value); \
		void GMap_Clear(GMapO_##GKEY_##GVALUE* obj); \
		void GMap_Remove(GMapO_##GKEY_##GVALUE* obj, const GKEY key); \
		void GMap_Size(GMapO_##GKEY_##GVALUE* obj); \
		void GMap_Show(GMapO_##GKEY_##GVALUE* obj); \
		\
		void GMap_RemoveNode(GMapNodeO_##GKEY_##GVALUE* node); \
		\
		GMapO_##GKEY_##GVALUE* GMap_New() { \
			GMapO_##GKEY_##GVALUE* lObj = (GMapO_##GKEY_##GVALUE*)malloc(sizeof(GMapO_##GKEY_##GVALUE)); \
			\
			lObj->Delete = GMap_Delete; \
			lObj->SetData = GMap_SetData; \
			lObj->Clear = GMap_Clear; \
			lObj->Remove = GMap_Remove; \
			lObj->Show = GMap_Show; \
			lObj->Size = GMap_Size; \
			lObj->m_head = 0; \
			return lObj; \
		} \
		\
		void GMap_Delete(GMapO_##GKEY_##GVALUE* obj) { \
			if(obj != 0) { \
				obj->Clear(obj); \
				free(obj); \
				obj = 0; \
			} \
		} \
		\
		void GMap_SetData(GMapO_##GKEY_##GVALUE* obj, const GKEY key, const GVALUE value) { \
			GMapNodeO_##GKEY_##GVALUE* lNext = obj->m_head; \
			GMapNodeO_##GKEY_##GVALUE* lLast = 0; \
			while(lNext != 0) { \
				int lStrcmp = strcmp(lNext->m_key, key); \
				if(lStrcmp == 0) { \
					free(lNext->m_value); \
					int lValue = strlen(value) + 1; \
					lNext->m_value = (char*)malloc(sizeof(char)*lValue); \
					sprintf(lNext->m_value, "%s", value); \
					return; \
				} \
				lLast = lNext; \
				lNext = lNext->m_next; \
			} \
			\
			GMapNodeO_##GKEY_##GVALUE* lNode = (GMapNodeO_##GKEY_##GVALUE*)malloc(sizeof(GMapNodeO_##GKEY_##GVALUE)); \
			int lKey = strlen(key) + 1; \
			int lValue = strlen(value) + 1; \
			lNode->m_key = (char*)malloc(sizeof(char)*lKey); \
			lNode->m_value = (char*)malloc(sizeof(char)*lValue); \
			sprintf(lNode->m_key, "%s", key); \
			sprintf(lNode->m_value, "%s", value); \
			lNode->m_next = 0; \
			\
			if(lLast == 0) obj->m_head = lNode; \
			else lLast->m_next = lNode; \
		} \
		\
		void GMap_Clear(GMapO_##GKEY_##GVALUE* obj) { \
			GMapNodeO_##GKEY_##GVALUE* lNext = obj->m_head; \
			while(lNext != 0) { \
				GMapNodeO_##GKEY_##GVALUE* lLast = lNext; \
				lNext = lNext->m_next; \
				GMap_RemoveNode(lLast); \
			} \
			obj->m_head = 0; \
		} \
		\
		void GMap_Remove(GMapO_##GKEY_##GVALUE* obj, const GKEY key) { \
			GMapNodeO_##GKEY_##GVALUE* lNode = obj->m_head; \
			GMapNodeO_##GKEY_##GVALUE* lPrevious = 0; \
			while(lNode != 0) { \
				int lStrcmp = strcmp(lNode->m_key, key); \
				if(lStrcmp == 0) { \
					if(lPrevious != 0) lPrevious->m_next = lNode->m_next; \
					else obj->m_head = lNode->m_next; \
					GMap_RemoveNode(lNode); \
					return; \
				} \
				lPrevious = lNode; \
				lNode = lNode->m_next; \
			} \
		} \
		\
		void GMap_Size(GMapO_##GKEY_##GVALUE* obj) { \
			GMapNodeO_##GKEY_##GVALUE* lNext = obj->m_head; \
			int lSize = 0; \
			\
			while(lNext != 0) { \
				lSize++; \
				lNext = lNext->m_next; \
			} \
			printf("[ SIZE ] : %d...\n", lSize); \
		} \
		\
		void GMap_Show(GMapO_##GKEY_##GVALUE* obj) { \
			GMapNodeO_##GKEY_##GVALUE* lNode = obj->m_head; \
			\
			while(lNode != 0) { \
				char* lKey = lNode->m_key; \
				char* lValue = lNode->m_value; \
				printf("%s = %s\n", lKey, lValue); \
				lNode = lNode->m_next; \
			} \
			printf("\n"); \
		} \
		\
		void GMap_RemoveNode(GMapNodeO_##GKEY_##GVALUE* node) { \
			if(node != 0) { \
				if(node->m_key != 0) { \
					free(node->m_key); \
					node->m_key = 0; \
				} \
				if(node->m_value != 0) { \
					free(node->m_value); \
					node->m_value = 0; \
				} \
				free(node); \
				node = 0; \
			} \
		}
//===============================================
#define GMapNodeO(GKEY, GVALUE) \
		GMapNodeO##GKEY_##GVALUE
//===============================================
#define GMapO(GKEY, GVALUE) \
		GMapO_##GKEY_##GVALUE
//===============================================
#endif
//===============================================
		\
        		void GMap_##GTYPE_Delete(GMapO_##GTYPE* obj);

		void GMap_##GTYPE_SetData(GMapO_##GTYPE* obj, const GKEY* key, const GVALUE* value); \
		void GMap_##GTYPE_Clear(GMapO_##GTYPE* obj); \
		void GMap_##GTYPE_Remove(GMapO_##GTYPE* obj, const GKEY* key); \
		void GMap_##GTYPE_Size(GMapO_##GTYPE* obj); \
		void GMap_##GTYPE_Show(GMapO_##GTYPE* obj); \
        		\
		void GMap_##GTYPE_RemoveNode(GMapNodeO_##GTYPE* node); \

