#include <stdio.h>

int main() {
    int size;
    printf("Enter the size= ");
    scanf("%d", &size);

    int arr[size];
    printf("Array = ");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    int k = 0;
    for (int i=0; i<size; i++){
        if (arr[i]!=0){
            arr[k++]=arr[i];
        }
    }

    printf("Compressed array = ");
    for (int i=0; i<k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
