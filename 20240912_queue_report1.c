#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

typedef struct {
    int data[SIZE];  
    int front;  
    int rear;   
}   LinearQueue;

void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;  
}

bool isFull(LinearQueue *q) {
    return q->rear == SIZE -1;
}

bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }

    q->rear++;
    q->data[q->rear] = value;
    return true;
}

int dequeue(LinearQueue *q) {
    if(isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    
    int value = q->data[q->front];
    q->front++;
    if(isEmpty(q)) {
        initQueue(q);
        printf("큐가 초기화되었습니다.\n");
    }
    return value;
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int menu = 0;
    
    while (1) {
        printf("----------------------\n");
        printf("메뉴를 선택해주세요.\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        scanf("%d", &menu);
        
        switch(menu) {
            case 1:
                int value;
                printf("삽입할 데이터:\t");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
                
            case 2:
                printf("Dequeue: %d\n", dequeue(&q));
                break;
                
            case 3:
                if(isEmpty(&q)) {
                    printf("큐가 비어있습니다.\n");
                }
                
                for(int i=q.front; i<=q.rear; i++) {
                    printf("queue: %d\n", q.data[i]);
                }
                break;
                
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            
            default:
                printf("잘못된 접근입니다.\n");
                break;   
        }  //swiy\switch
    }//while


    return 0;
}