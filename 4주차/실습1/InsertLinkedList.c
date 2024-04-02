﻿#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "InsertLinkedList.h"
//공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

//연결 리스트를 순서대로 출력하는 연산
void  printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (L->head == NULL) {  // 공백 리스트인 경우
        newNode->link = NULL; // 새 노드를 첫번째이자 마지막 노드로 연결
        L->head = newNode;
    }
    else if (pre == NULL) { // 삽입 위치를 지정하는 포인터 pre가 NULL인경우
        newNode->link = L->head;
        L->head = newNode; // 새 노드를 첫 번째 노드로 삽입
    }
    else {
        newNode->link = pre->link; // 포인터 pre의 노드 뒤에 새 노드 연결
        pre->link = newNode;
    }
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (L->head == NULL) {  //현재 리스트가 공백인 경우
        L->head = newNode;  // 새 노드를 리스트의 시작 노드로 연결
        return;
    }
    // 현재 리스트가 공백이 아닌 경우
    temp = L->head;
    while (temp->link != NULL) temp = temp->link; // 현재 리스트의 마지막 노드를 찾음
    temp->link = newNode;                       // 새 노드를 마지막 노드(temp)의 다음 노드
}