#include <bits/stdc++.h>
using namespace std;
int main()
{
    string arr1;
    cout << "Enter the array: ";
    cin >> arr1;
    int len = arr1.size();
    string arr2(len, ' ');
    int i=0;
    while(i<len){
        arr2[len-1-i] = arr1[i];
        i++;
    }
    bool isPalindrome = true;
    int j=0;
    while(j<len){
        if(arr1[j]!=arr2[j]){
            isPalindrome = false;
            break;
        }
        j++;
    }
    if(isPalindrome == true){
        cout << "The array is a palindrome." << endl;
    }
    else{
        cout << "The array is not a palindrome." << endl;
    }
    return 0;
}
