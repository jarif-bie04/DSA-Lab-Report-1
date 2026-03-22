#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter the values:" << endl;
    int arr[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    int temp1, temp2;

    temp1 = arr[0];
    for(int j=0; j<size; j++){
        if(arr[j] >= temp1){
            temp1 = arr[j];
        }
    }
    temp2 = INT_MIN;
    for(int j=0; j<size; j++){
        if((arr[j] >= temp2)&&(arr[j] != temp1)){
            temp2 = arr[j];
        }
    }

    int temp3, temp4;

    temp3 = arr[0];
    for(int j=0; j<size; j++){
        if(arr[j] <= temp3){
            temp3 = arr[j];
        }
    }
    temp4 = INT_MAX;
    for(int j=0; j<size; j++){
        if((arr[j] <= temp4)&&(arr[j] != temp3)){
            temp4 = arr[j];
        }
    }

    cout << "2nd Largest= " << temp2 << endl;
    cout << "2nd Smallest= " << temp4 << endl;
    return 0;
}
