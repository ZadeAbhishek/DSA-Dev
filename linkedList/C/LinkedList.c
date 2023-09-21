#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
};


void printList(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->value);
        head = head->next;
    }
    printf("\n");
    return;
}

int main(){
    struct Node *head;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;

    // Allocate Memory
    one = (struct Node *) malloc(sizeof(struct Node)); // type casting needs to be done in order to covert void to node type
    two = (struct Node *) malloc(sizeof(struct Node));
    three = (struct Node *) malloc(sizeof(struct Node));

    one->value = 1;
    two->value = 2;
    three->value = 3;
    
    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    printList(head);
}
