
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(void){
    struct node *head,*temp = NULL,*newnode;
    head=0;
    int choice=1;
    while(choice){
        newnode= (struct node *)malloc(sizeof(struct node));
        printf("enter the data:\n");
        scanf("%d",&newnode->data);
        if(head==NULL){
            head=temp=newnode;
            
        }
        else{
            temp->next = newnode;
                temp = newnode;
            newnode->next = NULL;
        }
        printf("do u want to continue(0/1)\n");
        scanf("%d",&choice);
        
    }
    printf("linked list\n");
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("insert at start\n");
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("enter the data:\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf("linked list\n");
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("insert at middle\n");
    int pos,i=1;
    printf("pos:\n");
    scanf("%d",&pos);
    
    temp=head;
    while(i<pos-1&& temp != NULL){
        temp=temp->next;
        i++;
    }
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("enter the data:\n");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
    printf("linked list\n");
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("insert at end\n");
    temp = head;
    while(temp->next!=0){
        temp=temp->next;
        
    }
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("enter the data:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp->next=newnode;
    printf("linked list\n");
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("delete at start");
    temp=head;
    head=head->next;
    free(head);
    printf("linked list\n");
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n delete in end");
    struct node *prev = NULL;
    temp=head;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
        
        
    }
    prev->next =temp->next;
    
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n delete in middle");

    temp=head;
   
    printf("pos:\n");
    scanf("%d",&pos);
    while(i<pos&&temp->next!=0){
        prev=temp;
        temp=temp->next;
        
    }
    prev->next =temp->next;
    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return 0;
}
