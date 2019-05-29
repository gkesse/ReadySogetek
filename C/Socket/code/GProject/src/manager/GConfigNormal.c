//===============================================
#include "GConfigNormal.h"
//===============================================
static GConfigO* m_GConfigNormalO = 0;
//===============================================
static void GConfigNormal_Clear();
static void GConfigNormal_Remove(char* key);
static void GConfigNormal_Remove_Node(GConfigNodeO* node);
static void GConfigNormal_SetData(char* key, char* value);
char* GConfigNormal_GetData(char* key);
static void GConfigNormal_Show();
//===============================================
GConfigO* GConfigNormal_New() {
    GConfigO* lParent = GConfig_New();
    GConfigNormalO* lChild = (GConfigNormalO*)malloc(sizeof(GConfigNormalO));

    lChild->m_parent = lParent;
    lChild->m_start = 0;
    lChild->m_size = 0;

    lParent->m_child = lChild;
    lParent->Delete = GConfigNormal_Delete;
    lParent->SetData = GConfigNormal_SetData;
    lParent->GetData = GConfigNormal_GetData;
    lParent->Show = GConfigNormal_Show;
    lParent->Clear = GConfigNormal_Clear;
    lParent->Remove = GConfigNormal_Remove;
    return lParent;
}
//===============================================
void GConfigNormal_Delete() {
    GConfigNormal_Clear();
    GConfig_Delete();
}
//===============================================
GConfigO* GConfigNormal() {
    if(m_GConfigNormalO == 0) {
        m_GConfigNormalO = GConfigNormal_New();
    }
    return m_GConfigNormalO;
}
//===============================================
static void GConfigNormal_Clear() {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
    GConfigNodeO* lNode = lConfigNormal->m_start;
    while(lNode != 0) {
        GConfigNodeO* lNext = lNode->m_next;
        GConfigNormal_Remove_Node(lNode);
        lNode = lNext;
    }
}
//===============================================
static void GConfigNormal_Remove(char* key) {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
    GConfigNodeO* lNode = lConfigNormal->m_start;
    GConfigNodeO* lPrevious = 0;
    GConfigNodeO* lNext = 0;
    while(lNode != 0) {
        lNext = lNode->m_next;
        int lStrcmp = strcmp(lNode->m_key, key);
        if(lStrcmp == 0) {
            if(lPrevious == 0) {
                lConfigNormal->m_start = lNext;
            }
            else {
                lPrevious->m_next = lNext;
            }
            GConfigNormal_Remove_Node(lNode);
            break;
        }
        lPrevious = lNode;
        lNode = lNode->m_next;
    }
}
//===============================================
static void GConfigNormal_Remove_Node(GConfigNodeO* node) {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
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
        if(lConfigNormal->m_size > 0) lConfigNormal->m_size -= 1;
    }
}
//===============================================
static void GConfigNormal_SetData(char* key, char* value) {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
    int lExist = FALSE;
    GConfigNodeO* lNode = lConfigNormal->m_start;
    while(lNode != 0) {
        int lStrcmp = strcmp(lNode->m_key, key);
        if(lStrcmp == 0) {
            sprintf(lNode->m_value, "%s", value);
            lExist = TRUE;
            break;
        }
        lNode = lNode->m_next;
    }

    if(lExist == FALSE) {
        lNode = (GConfigNodeO*)malloc(sizeof(GConfigNodeO));
        int lKey = strlen(key) + 1;
        int lValue = strlen(value) + 1;
        lNode->m_key = (char*)malloc(sizeof(char)*lKey);
        lNode->m_value = (char*)malloc(sizeof(char)*lValue);
        sprintf(lNode->m_key, "%s", key);
        sprintf(lNode->m_value, "%s", value);
        lNode->m_next = 0;
        lNode->m_index = lConfigNormal->m_size;
        if(lConfigNormal->m_start == 0) {
            lConfigNormal->m_start = lNode;
            lConfigNormal->m_size += 1;
            return;
        }

        GConfigNodeO* lNode2 = lConfigNormal->m_start;
        while(lNode2->m_next != 0) {
            lNode2 = lNode2->m_next;
        }
        lNode2->m_next = lNode;
        lConfigNormal->m_size += 1;
    }
}
//===============================================
char* GConfigNormal_GetData(char* key) {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
    GConfigNodeO* lNode = lConfigNormal->m_start;
    while(lNode != 0) {
        int lStrcmp = strcmp(lNode->m_key, key);
        if(lStrcmp == 0) {
            return lNode->m_value;
        }
        lNode = lNode->m_next;
    }
    return "_NONE_";
}
//===============================================
static void GConfigNormal_Show() {
    GConfigNormalO* lConfigNormal = m_GConfigNormalO->m_child;
    GConfigNodeO* lNode = lConfigNormal->m_start;
    while(lNode != 0) {
        char* lKey = lNode->m_key;
        char* lValue = lNode->m_value;
        printf("%s = %s\n", lKey, lValue);
        lNode = lNode->m_next;
    }
}
//===============================================
