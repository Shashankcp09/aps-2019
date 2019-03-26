#include<stdio.h>
#include<stdlib.h>
#define SS 5
struct stack
{
    int a[SS];
    int top;
};
void push(struct stack* s,int element)
{
    if(s->top==SS)
    printf("stack is full\n");
    else
    {
        s->top++;
        s->a[s->top]=element;
    printf("pushed element=%d\n",element);
    }
    
    
}
void pop(struct stack* s)
{
    if(s->top==-1)
    printf("stack is empty");
    else
    {
    printf("popped element is %d",s->a[s->top]);
    (s->top)--;
    }
}
void peek(struct stack* s)
{
    if(s->top==-1)
    printf("stack is empty");
    else
    {
    printf("top element is %d",s->a[s->top]);
    }
}
int main()
{
    struct stack s;
    s.top=-1;
    while(1)
    {
    printf("\nMENU\n1-push\n2-pop\n3-peek\n4-display\n");
    int ch;
    scanf("%d",&ch);
    int ele;
    switch(ch)
    {
        case 1:
        scanf("%d",&ele);
        push(&s,ele);
        break;
        case 2:
        pop(&s);
        break;
        case 3:
        peek(&s);
        break;
        
    }
    }
    return 0;
}