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

void update_value(struct node** head, int old_val, int new_val){
    if(*head == NULL){
        printf("There is no Linked List");
        return;
    }

    struct node* temp = *head;

    while(temp != NULL && temp->data == old_val){
        temp->data = new_val;
        temp = temp->next;
    }

    while(temp != NULL){
        if(temp->data == old_val){
            temp->data = new_val;
        }
        temp = temp->next;
    }

    printf("\nAfter updated specific value, linked list is: ");
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

    int old_val, new_val;
    printf("Enter the specific value that should be updated: ");
    scanf("%d",&old_val);
    printf("Enter the update value: ");
    scanf("%d",&new_val);

    printf("The original linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    update_value(&head, old_val, new_val);

    return 0;
}
