#include<bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int number;
    cin>> number;
    
    int divide = number%10;
    int number2 = number;
    int count = 0;
    
    while(number2 > 0){
        if(number%divide == 0){
            count = count + 1;
        }
        number2 = number2/10;
        divide = number2%10;
    }
    cout<<count <<endl;
    return count;
}