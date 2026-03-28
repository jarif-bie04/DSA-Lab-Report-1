#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cout << "Size of an array = ";
    cin >> len;
    cout << "Array = ";
    int arr[len];
    for(int i=0; i<len; i++){
        cin >> arr[i];
    }
    int old_val, new_val;
    cout << "Old value = ";
    cin >> old_val;
    cout << "New value = ";
    cin >> new_val;
    for(int i=0; i<len; i++){
        if(old_val==arr[i]){
            arr[i]=new_val;
        }
    }
    cout << "Updated Array = ";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
