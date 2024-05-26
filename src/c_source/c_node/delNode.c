#include <system/struct.h>
#include <system/nodeHandle.h>

NodePtr deleteNode(char string[], NodePtr Root) {
    NodePtr pNodeToDel = searchNode(Root, string);
    if (pNodeToDel == NULL) {
        return NULL; 
    }
    pNodeToDel->status = 0; 

    NodePtr pParent = Root;
    NodePtr pPrevSi = NULL;
    while (pParent != NULL) {
        if (pParent->child == pNodeToDel) {
            pPrevSi = pParent;
            break;
        }
        for (pPrevSi = pParent->child; pPrevSi->nextSi != NULL; pPrevSi = pPrevSi->nextSi) {
            if (pPrevSi->nextSi == pNodeToDel) {
                break;
            }
        }
        if (pPrevSi != NULL) {
            break;
        }
        pParent = pParent->nextSi;
    }

    if (pNodeToDel->nextSi != NULL) {
        if (pPrevSi != NULL) {
            pPrevSi->nextSi = pNodeToDel->nextSi;
        }
        pNodeToDel->nextSi = NULL; 
        NodePtr pLastSibling = pNodeToDel;
        while (pLastSibling->nextSi != NULL) {
            pLastSibling = pLastSibling->nextSi;
        }
        pLastSibling->nextSi = pNodeToDel;
    }

 NodePtr pCurrent, pNext;
    for (pCurrent = pParent->child; pCurrent != NULL; pCurrent = pNext) {
        pNext = pCurrent->nextSi;
        if (pNext != NULL && strcmp(pCurrent->name, pNext->name) > 0) {
            if (pPrevSi != NULL) {
                pPrevSi->nextSi = pNext;
            } else {
                pParent->child = pNext;
            }
            pCurrent->nextSi = pNext->nextSi;
            pNext->nextSi = pCurrent;
            pPrevSi = NULL;
            pNext = pParent->child;
        } else {
            pPrevSi = pCurrent;
        }
    }

    return Root;
}