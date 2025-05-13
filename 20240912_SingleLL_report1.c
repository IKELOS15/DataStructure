#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;           
    struct Node* next;  
} Node;

//IN
Node* insertFirst(Node* head, int data) {
    // 새로운 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // 새로운 노드는 초기에는 아무것도 가리키지 않음

    // Head가 NULL인 경우 (리스트가 비어 있음)
    if (head == NULL) {
        return newNode; // 새 노드가 리스트의 시작점이 됨
    }

    // Head가 NULL이 아닌 경우 (리스트에 기존 노드가 있음)
    newNode->next = head; // 새 노드의 다음을 기존 Head로 연결
    return newNode;       // 새 노드를 Head로 설정
} //맨앞 
Node* insertLast(Node* head, int data) {
    // 새로운 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // 새 노드는 리스트의 끝을 나타냄

    // 리스트가 비어 있는 경우
    if (head == NULL) {
        return newNode; // 새 노드가 리스트의 시작점이 됨
    }

    // 리스트에 기존 노드가 있는 경우
    Node* current = head;
    while (current->next != NULL) { // 마지막 노드를 찾음
        current = current->next;
    }
    current->next = newNode; // 마지막 노드의 next에 새 노드를 연결

    return head; // 리스트의 시작점(head) 반환
}    //맨뒤
void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    // 노드 탐색
    while (current != NULL) {
        if (current->data == targetValue) {
            // 새 노드 생성 및 삽입
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    // 값이 일치하는 노드가 없을 경우
    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}   //골라서

//OUT
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    Node* temp = head;     // 현재 헤드 노드를 임시 저장
    head = head->next;     // 헤드를 다음 노드로 변경
    free(temp);            // 이전 헤드 메모리 해제

    return head;
} //맨앞
Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    if (head->next == NULL) { // 리스트에 노드가 하나만 있는 경우
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) { // 마지막에서 두 번째 노드 찾기
        current = current->next;
    }

    free(current->next);    // 마지막 노드 메모리 해제
    current->next = NULL;   // 이전 노드의 next를 NULL로 설정

    return head;
}  //맨뒤
Node* deleteNode(Node* head, int targetValue) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }

    if (head->data == targetValue) { // 헤드 노드가 대상 값인 경우
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != targetValue) {
        current = current->next;
    }

    if (current->next == NULL) { // 대상 값을 찾지 못한 경우
        printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
        return head;
    }

    Node* temp = current->next;  // 삭제할 노드
    current->next = current->next->next; // 링크 재조정
    free(temp);                   // 삭제할 노드 메모리 해제

    return head;
}     //골라서

//add
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}    //1-4 과제1
int searchValue1(Node* head, int val) {
    Node* current = head;
    int count = 1;
    
    while (current != NULL) {
        if (current->data == val) {
            return count;
        }
        current = current->next;
        count++;
    }

    return -1;
}   //1-5-1
void searchValue2(Node* head, int val) {
    Node* current = head;
    Node* prev = NULL; 
    
    while (current != NULL) {
        if (current->data == val) {
            if (prev != NULL) {
                printf("앞 노드의 값: %d\n", prev->data);
            } else {
                printf("앞 노드가 없습니다. (현재 노드가 헤드 노드입니다.)\n");
            }
            
            if (current->next != NULL) {
                printf("뒤 노드의 값: %d\n", current->next->data);
            } else {
                printf("뒤 노드가 없습니다. (현재 노드가 마지막 노드입니다.)\n");
            }
            return;
        }
        
        prev = current;       
        current = current->next;
    }

    
    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", val);
}   //1-5-2
void freeList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;           
        current = current->next;  
        free(temp);               
    }

    printf("모든 노드가 메모리에서 해제되었습니다.\n");
}   //1-5-3

int main(){
    Node* head = NULL;
    int val = 30;
    if (head == NULL) {
        printf("리스트가 초기화되었습니다. 현재 리스트는 비어 있습니다.\n");
    }
    
    head = insertFirst(head, 30); // 첫 번째 노드 삽입
    head = insertFirst(head, 20); // 두 번째 노드 삽입
    head = insertFirst(head, 10); // 세 번째 노드 삽입
    head = insertLast(head, 70); // 세 번째 노드 삽입
    head = insertLast(head, 80); // 세 번째 노드 삽입
    head = insertLast(head, 90); // 세 번째 노드 삽입
    
    
    printList(head);

	int pos = searchValue1(head, val);
	printf("%d의 위치는 %d번째", val, pos);
    searchValue2(head, val);
    
    freeList(head);
    return 0;
}