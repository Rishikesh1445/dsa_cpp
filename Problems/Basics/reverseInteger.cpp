#include<bits/stdc++.h> 
using namespace std;

int main(){
    int input;
    cin >> input;
    bool negative = false;
    if(input<0){
        input = -input;
        negative = true;
    }
    int output = 0;
    while(input > 0){
        if((input%10)!=0){
            output = (output*10) + (input%10);
        }
        input = input/10;
    }
    if(negative){
        output = -output;
    }
    cout << output<<endl;
    return 0;
}