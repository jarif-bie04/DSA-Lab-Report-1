#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter the values of array: ";
    cin >> str;
    cout << "Original array: " << str << endl;
    for(int i=0; i<str.size(); i++){
        for(int j=i+1; j<str.size(); j++){
            if(i+j==str.size()-1){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Reversed array: " << str << endl;
    return 0;
}
