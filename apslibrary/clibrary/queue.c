#include<stdio.h>
#include<stdlib.h>
#define SS 5
struct queue
{
    int a[SS];
    int front;
    int rear;
};
void enqueue(struct queue* q,int element)
{
    if(q->rear==SS)
    printf("queue is full\n");
    else
    {
        q->rear++;
        q->a[q->rear]=element;
    printf("enqueued element=%d\n",element);
    }
    
    
}
void dequeue(struct queue* q)
{
    if(q->front>q->rear)
    printf("queue is empty");
    else
    {
    printf("dequeued element is %d",q->a[q->front]);
    (q->front)++;
    }
}
void display(struct queue* q)
{
    for(int i=q->front;i<=q->rear;i++)
    printf("%d:",q->a[i]);
    printf("\n");
}
int main()
{
    struct queue q;
    q.front=0;
    q.rear=-1;
    while(1)
    {
    printf("\nMENU\n1-enqueue\n2-dequeue\n3-display\n");
    int ch;
    scanf("%d",&ch);
    int ele;
    switch(ch)
    {
        case 1:
        scanf("%d",&ele);
        enqueue(&q,ele);
        break;
        case 2:
        dequeue(&q);
        break;
        case 3:
        display(&q);
        break;
        
    }
    }
    return 0;
}