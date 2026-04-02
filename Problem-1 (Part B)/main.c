#include <stdio.h>

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

void count_of_node(struct node* head){
    int count = 0;
    if(head==NULL){
        printf("There is no Linked List");
        return;
    }
    struct node* ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    printf("Total nodes = %d", count);
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
    count_of_node(head);

    return 0;
}
