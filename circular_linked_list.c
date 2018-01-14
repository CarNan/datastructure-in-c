#include<stdio.h>
#include<stdlib.h>
#define MALLOC(type) (type*)malloc(sizeof(type))

int isEmpty();
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAfterSpecific(int,int);
void deleteBeginning();
void deleteEnd();
void deleteSpecific(int);
void list();

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

int main(){
    int choice,subChoice,value,loc;
    choice=-1;
    subChoice=-1;
    while(choice!=4){
        printf("\n\n********* MENU ************\n1. Insert\n2. Delete\n3. List\n4.Exit\nEnter your subchoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:     printf("Where to insert: 1. At Beginning  2. At End 3. After specific , your choice: ");
		                scanf("%d",&subChoice);
                        printf("enter the value to be insert : ");
                        scanf("%d",&value);
                        switch(subChoice){
                            case 1:    insertAtBeginning(value);
                                       break;
                            case 2:    insertAtEnd(value);
                                       break;
                            case 3:    printf("insert after : ");
                                       scanf("%d",&loc);
                                       insertAfterSpecific(loc,value);
                                       break;
                        }
                        break;
            case 2:     printf("How to delete: 1. Beginning  2. End 3. Specific , your choice: ");
		                scanf("%d",&subChoice);
                        switch(subChoice){
                            case 1:    deleteBeginning();
                                       break;
                            case 2:    deleteEnd();
                                       break;
                            case 3:    printf("delete the node : ");
                                       scanf("%d",&loc);
                                       deleteSpecific(loc);
                        }
                        break;
            case 3:     list();
                        break;
        }
    }
    return 0;
}

int isEmpty(){
    if(head==NULL) return 1;
    else return 0;
}

void insertAtBeginning(int value){
    struct Node *newNode = MALLOC(struct Node);
    newNode->data=value;
    if(isEmpty()){
        head=newNode;
        newNode->next=head;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newNode->next=head;
        head=newNode;
        temp->next=head;
    }
    printf("insert at beginning success!\n");
}

void insertAtEnd(int value){
    struct Node *newNode = MALLOC(struct Node);
    newNode->data=value;
    if(isEmpty()){
        head=newNode;
        newNode->next=head;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
    printf("add at end success!\n");
}

void insertAfterSpecific(int loc,int value){
    struct Node *newNode=MALLOC(struct Node);
    newNode->data=value;
    struct Node *temp=head;
    if(isEmpty()){
        printf("node not found\n");
    }
    else{
        while(temp->data!=loc && temp->next!=head)
            temp=temp->next;
        if(temp->data!=loc)
            printf("node not found\n");
        else{
            newNode->next=temp->next;
            temp->next=newNode;
            printf("insert after loc=%d success\n",loc);
        }
    }
}

void deleteBeginning(){
    if(isEmpty())printf("list is Empty delete deny!\n");
    else{
        struct Node *temp=head;
        struct Node *temp2=head;
        if(temp->next==head){
            head=NULL;
            free(temp);
        }
        else{
            while(temp->next!=head)
                temp=temp->next;
            head=temp2->next;
            temp->next=head;
            free(temp2);
        }
        printf("delete at beginning success!\n");
    }
}

void deleteEnd(){
    if(isEmpty())
        printf("list is empty delete deny\n");
    else{
            struct Node *temp=head;
            if(temp->next==head){
                head=NULL;
                free(temp);
            }
            else{
                while(temp->next->next!=head)
                    temp=temp->next;
            struct Node *del=temp->next;
            temp->next=head;
            free(del);
            }
    }
}

void deleteSpecific(int loc){
    if(isEmpty()){
        printf("list is empty delete deny\n");
    }
    else{
        struct Node *temp=head;
        struct Node *temp2=head;
        while(temp->data!=loc && temp->next!=head){
            temp2=temp;
            temp=temp->next;
        }
        if(temp->data!=loc)
            printf("node not found\n");
        else if(temp==head){
            head=NULL;
            free(temp);
            printf("loc = %d delete\n",loc);
        }
        else{
            temp2->next=temp->next;
            free(temp);
            printf("loc = %d delete\n",loc);
        }
    }
}

void list(){
    if(isEmpty()){
        printf("list is Empty\n");
    }
    else{
        struct Node *temp=head;
        while(temp->next!=head){
            printf("%d ---> ",temp->data);
            temp=temp->next;
        }
        printf("%d ---> head \n",temp->data);

    }
}