#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPalindrom(string s ){
        string ss = "";
        for(char i : s){
            if((i>('a'-1))&(i<('z' +1))){
                ss = ss + i;
            }
            if((i>('A'-1))&(i<('Z' +1))){
                i = i + 32;
                ss = ss + i;
            }
        }

    }
};

int main(){
    string s = "Rishikesh is a - +   ";
    string ss = "";
        for(char i : s){
            if((i>('a'-1))&(i<('z' +1))){
                ss = ss + i;
            }
            if((i>('A'-1))&(i<('Z' +1))){
                i = i + 32;
                ss = ss + i;
            }
        }
    cout << ss;
}