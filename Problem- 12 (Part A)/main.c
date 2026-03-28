#include <stdio.h>

int main() {
    int size;
    printf("Enter the size= ");
    scanf("%d", &size);
    int arr[size];
    printf("Array = ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int target, insert_val;
    printf("Targeted value: ");
    scanf("%d", &target);
    printf("Inserted value: ");
    scanf("%d", &insert_val);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    int n_size = size + count;
    int new_arr[n_size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        new_arr[j++] = arr[i];
        if (arr[i] == target) {
            new_arr[j++] = insert_val;
        }
    }
    printf("New array is= ");
    for (int i = 0; i < n_size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");
    return 0;
}
