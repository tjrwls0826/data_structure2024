﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

//공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h)); // 헤드 노드 할당
    DL->head = NULL;                                  // 공백 리스트이므로 NULL
    return DL;
}


// 이중 연결 리스트를 순서대로 출력하는 연산
void  printList(linkedList_h* DL) {
    listNode* p;
    printf("DL = (");
    p = DL->head;

    while (p != NULL) {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL)printf(", ");
    }
    printf(") \n");
}

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (DL->head == NULL) {         //리스트가 공백인 경우
        newNode->rlink = NULL;
        newNode->llink = NULL;
        DL->head = newNode;         
    }
    else {                          
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if (newNode->rlink != NULL) // 삽입 자리에 다음 노드가 있는 경우
            newNode->rlink->llink = newNode;
    }
}


// 이중 연결 리스트에서 노드 old를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL) return;        //공백 리스트라면 삭제 연산 중단
    else if (old == NULL) return;         //삭제할 노드가 없다면 삭제 연산 중단
    else {
        old->llink->rlink = old->rlink;
        old->rlink->llink = old->llink;
        free(old);                        // 삭제 노드의 메모리 해제
    }
}
// 리스트에서 x노드 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp;
    temp = DL->head;
    if (temp == NULL) return NULL;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->rlink;
    }
    return temp;
}