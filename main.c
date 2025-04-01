/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

void halfcircle(Stack *s, char InString[])    {
    for(int i=0; i<100; i++){
        if((*InString + i) == '(' || (*InString + i) == '{' || (*InString + i) == '['){
            push(s, (*InString + i));
        }//괄호 열림림
        else if((*InString + i) == ')'){
            if(peek(s) == '(')  pop(s);
            else    printf("error");
            return;
        }// )일때
        else if((*InString + i) == '}'){
            if(peek(s) == '(')  pop(s);
            else    printf("error");
            return;
        }// }일때
        else if((*InString + i) == ']'){
            if(peek(s) == '[')  pop(s);
            else    printf("error");
            return;
        }// ]일때
    }
    printf("ewwerwr");
}

int main()
{
    Stack s;
    initStack(&s);
    char InString[100] = "";
    
    printf("문자열을 입력해주세요.\n");
    scanf("%s", InString);
    
    halfcircle(&s, InString);
    
    
    return 0;
}