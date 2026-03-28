#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size= ");
    scanf("%d",&size);
    int arr[size];
    printf("Array = ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int n_size = size+1;
    int new_arr[n_size];
    int x;
    printf("Insert the new element= ");
    scanf("%d",&x);
    int j=0;
    while(j<size){
        new_arr[j] = arr[j];
        j++;
    }
    new_arr[j] = x;
    int temp;
    for(int k=0; k<n_size-1; k++){
        for(int l=0; l<n_size-k-1; l++){
            if(new_arr[l]>new_arr[l+1]){
                temp = new_arr[l];
                new_arr[l] = new_arr[l+1];
                new_arr[l+1] = temp;
            }
        }
    }
    printf("New array is= ");
    for(int i=0; i<n_size; i++){
        printf("%d ", new_arr[i]);
    }
    return 0;
}
