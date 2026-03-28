#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sz;
    cout << "The size of an array= ";
    cin >> sz;

    int arr[sz], new_arr[sz];
    cout << "Enter the values of a array:" << endl;
    for(int i=0; i<sz; i++){
        cin >> arr[i];
    }

    int x;
    cout << "Removing element= ";
    cin >> x;

    int i = 0;
    for(int j=0; j<sz; j++){
        if(arr[j]!=x){
            new_arr[i]=arr[j];
            i++;
        }
    }
    cout << "The new array is: ";
    for(int k=0; k<i; k++){
        cout << new_arr[k] << " ";
    }

    return 0;
}
