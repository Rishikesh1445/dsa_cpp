#include <bits/stdc++.h>
using namespace std;

void printName( string name){
    cout << "Printing name from function " << name << endl;
}

int therila(){
    return 5;
}

void dummy(int &number){
    number = number + 5;
}

void doSomething ( int arr[]){
    // directly pass the array
    // for array, by default it passes the pointer, any changes here reflects in main.
}


int main(){
    string name1;
    cin >> name1;
    printName(name1);

    int summa = therila();

    cout << summa << endl;

    int num1 , num2;
    int maximum = max(num1, num2);

    int v = 5;
    dummy(v);

    cout << v << endl;
}

// function name should be equaivalent to any inbulit function
