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

void middle_node(struct node* head, int n){
    if(head == NULL){
        printf("There is no Linked List.");
        return;
    }
    struct node* ptr = NULL;
    ptr = head;
    int mid;
    if(n%2==0){
        mid = n/2;
    }
    else{
        mid = (n/2)+1;
    }
    int i=1;
    while(i<mid){
        ptr = ptr->next;
        i++;
    }
    printf("The middle node is: %d\n", ptr->data);
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

    middle_node(head, n);

    return 0;
}
