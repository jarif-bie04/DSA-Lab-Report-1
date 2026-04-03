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

void delete_specific_value(struct node** head, int val){
    if(*head == NULL){
        printf("There is no Linked List");
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    while(temp != NULL && temp->data == val){
        *head = temp->next;
        free(temp);
        temp =*head;
    }

    while(temp != NULL){
        if(temp->data == val){
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }

    printf("\nAfter deleted specific value, linked list is: ");
    struct node* ptr = *head;
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

    int val;
    printf("Enter the specific value that should be deleted: ");
    scanf("%d",&val);

    printf("The original linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    delete_specific_value(&head, val);

    return 0;
}
