#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node NODE;
NODE* insert(NODE* root)
{
    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("memory failed!!\n");
    }
    printf("enter the tree data\n");
    scanf("%d",&newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        return newnode;
    }
    NODE *prev=NULL,*cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->data > newnode->data)
        cur=cur->left;
        else
        cur=cur->right;
    }
    if(prev->data > newnode->data)
    prev->left=newnode;
    else
    prev->right=newnode;
    return root;
}
void inorder(NODE* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
NODE* delete_bst(NODE* root)
{
    if(root==NULL)
    {
        printf("tree is empty!!\n");
        return root;
    }
    int data;
    printf("enter the data to be deleted\n");
    scanf("%d",&data);
    NODE *par,*cur,*succ,*p;
    while(cur!=NULL && cur->data!=data)
    {
        par=cur;
        if(cur->data > data)
        cur=cur->left;
        else
        cur=cur->right;
    }
    if(cur==NULL)
    {
        printf("data not found\n");
        return root;
    }
    if(cur->left==NULL)
    {
        p=cur->right;
    }
    else if(cur->right==NULL)
    {
        p=cur->left;
    }
    else
    {
        succ=cur->right;
        while(succ->left!=NULL)
        succ=succ->left;
        succ->left=cur->left;
        p=cur->right;
    }
    
    
}
int main()
{

    return 0;
}