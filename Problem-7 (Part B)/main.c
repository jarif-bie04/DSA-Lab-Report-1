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

void check_palindrome(struct node* head){
    if(head == NULL){
        printf("There is no Linked List\n");
        return;
    }

    int count = 0;
    struct node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    int arr[count];
    temp = head;
    int i = 0;
    while(temp != NULL){
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int flag = 1;
    for(int j = 0; j < count/2; j++){
        if(arr[j] != arr[count - j - 1]){
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("\nThe linked list is a palindrome.\n");
    else
        printf("\nThe linked list is NOT a palindrome.\n");
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

    check_palindrome(head);

    return 0;
}
