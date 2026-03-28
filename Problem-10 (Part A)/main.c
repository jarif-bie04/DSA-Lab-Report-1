#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("The size of an array = ");
    scanf("%d", &size);
    int arr[size];
    printf("Array = ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int new_arr[size];
    int k = 0;
    for (int i = 0; i < size; i++){
        int isDuplicate = 0;
        for (int j = 0; j < k; j++){
            if (arr[i] == new_arr[j]){
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate){
            new_arr[k++] = arr[i];
        }
    }
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++){
        printf("%d ", new_arr[i]);
    }
    printf("\n");
    return 0;
}
