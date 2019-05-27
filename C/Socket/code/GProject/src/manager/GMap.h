//===============================================
#ifndef _GMap_
#define _GMap_
//===============================================
#include "GInclude.h"
//===============================================
#define GDECLARE_MAP(GKEY, GVALUE, GTYPE) \
		typedef struct _GMapNodeO_##GTYPE GMapNodeO_##GTYPE; \
		typedef struct _GMapO_##GTYPE GMapO_##GTYPE; \
		typedef int (*GEQUAL_##GTYPE)(GKEY key1, GKEY key2); \
		typedef void (*GSHOW_##GTYPE)(GKEY key, GVALUE value); \
		\
		struct _GMapNodeO_##GTYPE { \
			GKEY m_key; \
			GVALUE m_value; \
			GMapNodeO_##GTYPE* m_next; \
		}; \
		\
		struct _GMapO_##GTYPE { \
			void (*Delete)(GMapO_##GTYPE* obj); \
			void (*SetData)(GMapO_##GTYPE* obj, GKEY key, GVALUE value, GEQUAL_##GTYPE equal); \
			GVALUE (*GetData)(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal, GVALUE defaultValue); \
			void (*Clear)(GMapO_##GTYPE* obj); \
			void (*Remove)(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal); \
			void (*Size)(GMapO_##GTYPE* obj); \
			void (*Show)(GMapO_##GTYPE* obj, GSHOW_##GTYPE show); \
			GMapNodeO_##GTYPE* m_head; \
		}; \
		\
		GMapO_##GTYPE* GMap_New_##GTYPE(); \
		void GMap_Delete_##GTYPE(GMapO_##GTYPE* obj); \
		void GMap_Clear_##GTYPE(GMapO_##GTYPE* obj); \
		void GMap_Remove_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal); \
		void GMap_RemoveNode_##GTYPE(GMapNodeO_##GTYPE* node); \
		void GMap_SetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GVALUE value, GEQUAL_##GTYPE equal); \
		GVALUE GMap_GetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal, GVALUE defaultValue); \
		void GMap_Size_##GTYPE(GMapO_##GTYPE* obj); \
		void GMap_Show_##GTYPE(GMapO_##GTYPE* obj, GSHOW_##GTYPE show);
//===============================================
#define GDEFINE_MAP(GKEY, GVALUE, GTYPE) \
		\
		GMapO_##GTYPE* GMap_New_##GTYPE() { \
			GMapO_##GTYPE* lObj = (GMapO_##GTYPE*)malloc(sizeof(GMapO_##GTYPE)); \
			\
			lObj->Delete = GMap_Delete_##GTYPE; \
			lObj->Clear = GMap_Clear_##GTYPE; \
			lObj->Remove = GMap_Remove_##GTYPE; \
			lObj->SetData = GMap_SetData_##GTYPE; \
			lObj->GetData = GMap_GetData_##GTYPE; \
			lObj->Size = GMap_Size_##GTYPE; \
			lObj->Show = GMap_Show_##GTYPE; \
			lObj->m_head = 0; \
			return lObj; \
		} \
		\
		void GMap_Delete_##GTYPE(GMapO_##GTYPE* obj) { \
			if(obj != 0) { \
				obj->Clear(obj); \
				free(obj); \
				obj = 0; \
			} \
		} \
		\
		void GMap_Clear_##GTYPE(GMapO_##GTYPE* obj) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			while(lNext != 0) { \
				GMapNodeO_##GTYPE* lPrevious = lNext; \
				lNext = lNext->m_next; \
				GMap_RemoveNode_##GTYPE(lPrevious); \
			} \
			obj->m_head = 0; \
		} \
		\
		void GMap_Remove_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			GMapNodeO_##GTYPE* lPrevious = 0; \
			\
			while(lNext != 0) { \
				GKEY lKey = lNext->m_key; \
				int lEqual = FALSE; \
				if(equal == 0) lEqual = (lKey == key) ? TRUE : FALSE; \
				else lEqual = equal(lKey, key); \
				if(lEqual == TRUE) { \
					if(lPrevious == 0) obj->m_head = lNext->m_next; \
					else lPrevious->m_next = lNext->m_next; \
					GMap_RemoveNode_##GTYPE(lNext); \
					return; \
				} \
				lPrevious = lNext; \
				lNext = lNext->m_next; \
			} \
		} \
		\
		void GMap_RemoveNode_##GTYPE(GMapNodeO_##GTYPE* node) { \
			if(node != 0) { \
				free(node); \
				node = 0; \
			} \
		} \
		\
		void GMap_SetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GVALUE value, GEQUAL_##GTYPE equal) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			GMapNodeO_##GTYPE* lPrevious = 0; \
			\
			while(lNext != 0) { \
				GKEY lKey = lNext->m_key; \
				int lEqual = FALSE; \
				if(equal == 0) lEqual = (lKey == key) ? TRUE : FALSE; \
				else lEqual = equal(lKey, key); \
				if(lEqual == TRUE) { \
					lNext->m_value = value; \
					return; \
				} \
				lPrevious = lNext; \
				lNext = lNext->m_next; \
			} \
			\
			GMapNodeO_##GTYPE* lNode = (GMapNodeO_##GTYPE*)malloc(sizeof(GMapNodeO_##GTYPE)); \
			lNode->m_key = key; \
			lNode->m_value = value; \
			lNode->m_next = 0; \
			\
			if(lPrevious == 0) obj->m_head = lNode; \
			else lPrevious->m_next = lNode; \
		}\
		\
		GVALUE GMap_GetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GEQUAL_##GTYPE equal, GVALUE defaultValue) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			\
			while(lNext != 0) { \
				GKEY lKey = lNext->m_key; \
				GVALUE lValue = lNext->m_value; \
				int lEqual = FALSE; \
				if(equal == 0) lEqual = (lKey == key) ? TRUE : FALSE; \
				else lEqual = equal(lKey, key); \
				if(lEqual == TRUE) return lValue; \
				lNext = lNext->m_next; \
			} \
			return defaultValue; \
		} \
		\
		void GMap_Size_##GTYPE(GMapO_##GTYPE* obj) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			int lSize = 0; \
			\
			while(lNext != 0) { \
				lSize++; \
				lNext = lNext->m_next; \
			} \
			printf("[ SIZE ] %d...\n", lSize); \
		} \
		\
		void GMap_Show_##GTYPE(GMapO_##GTYPE* obj, GSHOW_##GTYPE show) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			\
			while(lNext != 0) { \
				GKEY lKey = lNext->m_key; \
				GVALUE lValue = lNext->m_value; \
				show(lKey, lValue); \
				lNext = lNext->m_next; \
			} \
			printf("\n"); \
		}
//===============================================
#define GMapO(GTYPE) \
		GMapO_##GTYPE
//===============================================
#define GMapNodeO(GTYPE) \
		GMapNodeO_##GTYPE
//===============================================
#endif
//===============================================
