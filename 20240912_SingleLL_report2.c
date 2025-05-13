#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];  // 연락처 이름
    char phone[MAX_PHONE_LENGTH]; // 연락처 전화번호
    struct Node* next;           // 다음 노드 포인터
} Node;

// 연락처 추가 (맨 앞에)
Node* insertFirst(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    strncpy(newNode->phone, phone, MAX_PHONE_LENGTH);
    newNode->next = head;
    return newNode;
}

// 연락처 추가 (맨 뒤에)
Node* insertLast(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    strncpy(newNode->phone, phone, MAX_PHONE_LENGTH);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// 특정 이름의 연락처를 검색하여 전화번호 확인
void searchContact(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("연락처: %s, 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("연락처 %s를 찾을 수 없습니다.\n", name);
}

// 특정 이름의 연락처 삭제
Node* deleteContact(Node* head, char* name) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 연락처가 없습니다.\n");
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("연락처 %s를 찾을 수 없습니다.\n", name);
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// 연락처 목록 출력
void printContacts(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("NULL\n");
}

// 리스트 메모리 해제
void freeList(Node* head) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    printf("모든 연락처가 메모리에서 해제되었습니다.\n");
}

int main() {
    Node* head = NULL;

    head = insertFirst(head, "John Doe", "010-1234-5678");
    head = insertFirst(head, "Alice", "010-2345-6789");
    head = insertLast(head, "Bob", "010-3456-7890");
    head = insertLast(head, "Charlie", "010-4567-8901");

    printf("현재 연락처 목록:\n");
    printContacts(head);

    // 특정 이름의 연락처 검색
    printf("\n검색 결과:\n");
    searchContact(head, "Alice");

    // 특정 이름의 연락처 삭제
    printf("\n삭제 후 연락처 목록:\n");
    head = deleteContact(head, "Bob");
    printContacts(head);

    freeList(head);
    return 0;
}
