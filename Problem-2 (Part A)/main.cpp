#include <bits/stdc++.h>
using namespace std;

int main()
{
    int freq_arr[256] = {0};
    string str;
    cout << "Enter the value of array: ";
    cin >> str;

    for(int i=0; i<str.size(); i++){
        freq_arr[str[i]]++;
    }
    for(int i=0; i<256; i++){
        if(freq_arr[i]>0){
            cout << (char) i << ": " << freq_arr[i] << endl;
        }
    }
    return 0;
}
