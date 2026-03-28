#include <stdio.h>
#include <stdlib.h>

void rotateArr(int arr[], int size, int k){
    for(int i=0; i<k; i++){
        int first = arr[0];
        for(int j=0; j<size-1;j++){
            arr[j] = arr[j+1];
        }
        arr[size-1] = first;
    }
}

int main()
{
    int size;
    printf("Enter the size of an array= ");
    scanf("%d", &size);

    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("The value of k for the left rotation= ");
    int k;
    scanf("%d", &k);

    rotateArr(arr, size, k);
    printf("Result= ");

    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
