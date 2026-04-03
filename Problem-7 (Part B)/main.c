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

void remove_duplicates(struct node* head){
    if(head == NULL){
        printf("There is no Linked List\n");
        return;
    }

    struct node* current = head;
    struct node* prev = NULL;
    struct node* temp = NULL;

    while(current != NULL){
        prev = current;
        temp = current->next;

        while(temp != NULL){
            if(temp->data == current->data){
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }

    printf("\nAfter removing duplicates, linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
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

    int old_val;
    printf("Targeted value: ");
    scanf("%d",&old_val);

    printf("The original linked list is: ");
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    remove_duplicates(head);

    return 0;
}
