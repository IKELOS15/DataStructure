#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
}   Stack;

void initStack(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s)  {
    return s->top == -1;
}

int isFull(Stack *s)   {
    return s->top == MAX -1;
}

void push(Stack *s, char value) {
    if(isFull(s))   {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;  // 에러 값
    }
    return s->data[s->top];
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;  // 에러 값
    }
    return s->data[(s->top)--];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

void stacking(char InString[], Stack *s)    {
    for(int i=99; i>-1; i--){
        if(*(InString + i) != '\0'){
            push(s, InString[i]);
        }
    } 
    
}

int main()
{
    Stack s;
    initStack(&s);
    char InString[100] = "";
    
    printf("문자열을 입력해주세요.\n");
    scanf("%s", InString);
    
    stacking(InString, &s);
    display(&s);

    return 0;
}