#include <bits/stdc++.h>
using namespace std;

int main(){
    int day;
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday"<< endl;
        break;
    case 3:
        cout << "Wednesday"<< endl;
        break;
    case 4:
        cout << "Thursday"<< endl;
        break;
    case 5:
        cout << "Friday"<< endl;
        break;
    default: //when nothing matches
        break;
    }
}

//if break not given , it executes all the condition below it also.