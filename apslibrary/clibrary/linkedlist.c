#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node NODE;
NODE* insert_start_beg(NODE* start)
{
    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("MEMORY FULL\n");
        return start;
    }
    printf("enter the data\n");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if(start==NULL)
    return newnode;
    else
    {
        newnode->next=start;
        return newnode;
    }
}
NODE* insert_start_end(NODE* start)
{
    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("MEMORY FULL\n");
        return start;
    }
    printf("enter the data\n");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if(start==NULL)
    return newnode;
    else
    {
        NODE* temp;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return start;
    }
}
NODE* delete_end(NODE* start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return start;
    }
    if(start->next==NULL)
    {
        free(start);
        return NULL;
    }
    NODE *cur,*prev;
    cur=start;
    prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
    return start;
}
NODE* delete_start(NODE* start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    if(start->next==NULL)
    {
        free(start);
        return NULL;
    }
    NODE* first;
    first=start->next;
    free(start);
    return first;
}
int main()
{
    NODE* start;
    int ch;
    NODE* temp;
    while(1)
    {
        printf("1.insertstart\n2.insertEnd\n3.deletestart\n4.deleteEnd\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            start=insert_start_beg(start);
            break;
            case 2:
            start=insert_start_end(start);
            break;
            case 3:
            start=delete_end(start);
            break;
            case 4:
            start=delete_start(start);
            break;
            case 5:
            temp=start;
            while(temp->next!=NULL)
            {
                printf("%d->",temp->data);
                temp=temp->next;
            }
            break;
        }
    }
    return 0;
}