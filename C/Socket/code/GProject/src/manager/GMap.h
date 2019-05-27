//===============================================
#ifndef _GMap_
#define _GMap_
//===============================================
#include "GInclude.h"
//===============================================
#define GDECLARE_MAP(GKEY, GVALUE, GTYPE) \
		typedef struct _GMapNodeO_##GTYPE GMapNodeO_##GTYPE; \
		typedef struct _GMapO_##GTYPE GMapO_##GTYPE; \
		\
		struct _GMapNodeO_##GTYPE { \
			GKEY m_key; \
			GVALUE m_value; \
			GMapNodeO_##GTYPE* m_next; \
		}; \
		\
		struct _GMapO_##GTYPE { \
			void (*Delete)(GMapO_##GTYPE* obj); \
			void (*SetData)(GMapO_##GTYPE* obj, const GKEY key, const GVALUE value); \
			void (*Clear)(GMapO_##GTYPE* obj); \
			void (*Remove)(GMapO_##GTYPE* obj, const GKEY key); \
			void (*Size)(GMapO_##GTYPE* obj); \
			void (*Show)(GMapO_##GTYPE* obj); \
			GMapNodeO_##GTYPE* m_head; \
		}; \
		\
		GMapO_##GTYPE* GMap_New_##GTYPE(); \
		void GMap_Delete_##GTYPE(GMapO_##GTYPE* obj); \
		void GMap_SetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GVALUE value); \
		void GMap_Size_##GTYPE(GMapO_##GTYPE* obj);
//===============================================
#define GDEFINE_MAP(GKEY, GVALUE, GTYPE) \
		\
		GMapO_##GTYPE* GMap_New_##GTYPE() { \
			GMapO_##GTYPE* lObj = (GMapO_##GTYPE*)malloc(sizeof(GMapO_##GTYPE)); \
			\
			lObj->Delete = GMap_Delete_##GTYPE; \
			lObj->SetData = GMap_SetData_##GTYPE; \
			lObj->Size = GMap_Size_##GTYPE; \
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
		void GMap_SetData_##GTYPE(GMapO_##GTYPE* obj, GKEY key, GVALUE value) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			GMapNodeO_##GTYPE* lLast = 0; \
			\
			while(lNext != 0) { \
				lLast = lNext; \
				lNext = lNext->m_next; \
			} \
			\
			GMapNodeO_##GTYPE* lNode = (GMapNodeO_##GTYPE*)malloc(sizeof(GMapNodeO_##GTYPE)); \
			lNode->m_key = key; \
			lNode->m_value = value; \
			lNode->m_next = 0; \
			\
			if(lLast == 0) obj->m_head = lNode; \
			else lLast->m_next = lNode; \
		}\
		\
		void GMap_Size_##GTYPE(GMapO_##GTYPE* obj) { \
			GMapNodeO_##GTYPE* lNext = obj->m_head; \
			int lSize = 0; \
			\
			while(lNext != 0) { \
				lSize++; \
				lNext = lNext->m_next; \
			} \
			printf("[ SIZE ] : %d...\n", lSize); \
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
