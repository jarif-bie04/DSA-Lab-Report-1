#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_begin(int value) {
    struct node* newNode = createNode(value);
    if(head == NULL) head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insert_end(int value) {
    struct node* newNode = createNode(value);
    if(head == NULL) head = newNode;
    else {
        struct node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insert_pos(int value, int pos) {
    if(pos == 1) { insert_begin(value); return; }
    struct node* temp = head;
    for(int i=1; temp!=NULL && i<pos-1; i++) temp = temp->next;
    if(temp == NULL) { printf("Position out of range!\n"); return; }
    struct node* newNode = createNode(value);
    newNode->next = temp->next;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_sorted(int value) {
    struct node* newNode = createNode(value);
    if(head == NULL || head->data >= value) { insert_begin(value); return; }
    struct node* temp = head;
    while(temp->next != NULL && temp->next->data < value) temp = temp->next;
    newNode->next = temp->next;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void delete_begin() {
    if(head == NULL) { printf("List empty!\n"); return; }
    struct node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
}

void delete_end() {
    if(head == NULL) { printf("List empty!\n"); return; }
    struct node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    if(temp->prev != NULL) temp->prev->next = NULL;
    else head = NULL;
    free(temp);
}

void delete_pos(int pos) {
    if(head == NULL) { printf("List empty!\n"); return; }
    struct node* temp = head;
    for(int i=1; temp!=NULL && i<pos; i++) temp = temp->next;
    if(temp == NULL) { printf("Position out of range!\n"); return; }
    if(temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void delete_all(int val) {
    struct node* temp = head;
    while(temp != NULL) {
        if(temp->data == val) {
            struct node* del = temp;
            if(del->prev != NULL) del->prev->next = del->next;
            else head = del->next;
            if(del->next != NULL) del->next->prev = del->prev;
            temp = del->next;
            free(del);
        } else temp = temp->next;
    }
}

void update_value(int old_val, int new_val) {
    struct node* temp = head;
    while(temp != NULL) {
        if(temp->data == old_val) { temp->data = new_val; return; }
        temp = temp->next;
    }
    printf("Value not found!\n");
}

struct node* copy_list(struct node* h) {
    if(h == NULL) return NULL;
    struct node* newHead = NULL, *tail = NULL, *temp = h;
    while(temp != NULL) {
        struct node* newNode = createNode(temp->data);
        if(newHead == NULL) { newHead = newNode; tail = newNode; }
        else { tail->next = newNode; newNode->prev = tail; tail = newNode; }
        temp = temp->next;
    }
    return newHead;
}

struct node* merge_lists(struct node* h1, struct node* h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    struct node* temp = h1;
    while(temp->next != NULL) temp = temp->next;
    temp->next = h2;
    h2->prev = temp;
    return h1;
}

void split_list(struct node* h, struct node** firstHalf, struct node** secondHalf) {
    if(h == NULL || h->next == NULL) { *firstHalf = h; *secondHalf = NULL; return; }
    struct node* slow = h;
    struct node* fast = h;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *firstHalf = h;
    *secondHalf = slow->next;
    slow->next = NULL;
    if(*secondHalf != NULL) (*secondHalf)->prev = NULL;
}

void display(struct node* h) {
    if(h == NULL) { printf("List empty!\n"); return; }
    struct node* temp = h;
    while(temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    int n, val, pos, choice, old_val, new_val;
    struct node* copied = NULL;
    struct node* head2 = NULL;
    struct node* firstHalf = NULL;
    struct node* secondHalf = NULL;

    printf("Enter initial size of linked list: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &val);
        insert_end(val);
    }

    while(1) {
        printf("\nDoubly Linked List Menu: \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert in Sorted List\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Delete All Occurrences\n");
        printf("9. Update a Value\n");
        printf("10. Copy Linked List\n");
        printf("11. Merge Two Linked Lists\n");
        printf("12. Split Linked List\n");
        printf("13. Display List\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert_begin(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insert_end(val); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &val, &pos); insert_pos(val,pos); break;
            case 4: printf("Enter value: "); scanf("%d", &val); insert_sorted(val); break;
            case 5: delete_begin(); break;
            case 6: delete_end(); break;
            case 7: printf("Enter position: "); scanf("%d", &pos); delete_pos(pos); break;
            case 8: printf("Enter value: "); scanf("%d", &val); delete_all(val); break;
            case 9: printf("Enter old and new value: "); scanf("%d %d", &old_val, &new_val); update_value(old_val,new_val); break;
            case 10: copied = copy_list(head); printf("Copied list: "); display(copied); break;
            case 11: {
                int m;
                printf("Enter size of second list: ");
                scanf("%d", &m);
                head2 = NULL;
                for(int i=0; i<m; i++) {
                    printf("Enter value for node %d: ", i+1);
                    scanf("%d", &val);
                    struct node* newNode = createNode(val);
                    if(head2 == NULL) head2 = newNode;
                    else {
                        struct node* temp = head2;
                        while(temp->next != NULL) temp = temp->next;
                        temp->next = newNode;
                        newNode->prev = temp;
                    }
                }
                head = merge_lists(head, head2);
                printf("Merged list: "); display(head);
                break;
            }
            case 12: split_list(head, &firstHalf, &secondHalf);
                     printf("First half: "); display(firstHalf);
                     printf("Second half: "); display(secondHalf);
                     break;
            case 13: display(head); break;
            case 14: exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
