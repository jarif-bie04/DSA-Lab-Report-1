#include <stdio.h>
#include <string.h>

int main()
{
    int size1, size2;
    int freq[256] = {0};
    printf("Enter the size of array 1= ");
    scanf("%d", &size1);
    printf("Enter the values of array 1: ");
    char arr1[size1];
    scanf("%s", arr1);
    printf("Enter the size of array 2= ");
    scanf("%d", &size2);
    printf("Enter the values of array 1:");
    char arr2[size2];
    scanf("%s", arr2);
    char new_arr[size1+size2];
    strcpy(new_arr, arr1);
    strcat(new_arr, arr2);
    for(int i=0; i<size1+size2; i++){
        if(freq[new_arr[i]]==0){
            printf("%c",new_arr[i]);
            freq[new_arr[i]]=1;
        }
    }
    return 0;
}
