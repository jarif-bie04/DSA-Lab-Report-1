#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void reverse_list(struct node* head){
    if(head == NULL){
        printf("There is no Linked List.");
        return;
    }
    struct node* temp = NULL;
    struct node* temp2 = NULL;
    while(head != NULL){
        temp2 = head->next;
        head->next = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
    printf("\nThe reversed linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* tail = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        printf("Enter the value of node- %d: ",i);
        scanf("%d", &value);

        temp = createNode(value);

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }


    printf("The original linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    reverse_list(head);

    return 0;
}
