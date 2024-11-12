#include <bits/stdc++.h>
using namespace std;

void unionofArray(vector<int> &array1, vector<int> &array2, vector<int> &array3){
    int i = 0;
    int j = 0;
    array3.emplace_back(array1[i]);
    i++;
    while((i<array1.size()) || (j<array2.size())){
        if((array1[i] <= array2[j]) || (array1[i]>array3.back())){
            
        }
    }
}

int main(){
    vector<int> array1 = {1,3,4,5,5,6};
    vector<int> array2 = {0,2,4,6,6,7,10};
    vector<int> array3;

    unionofArray(array1, array2, array3);

    for (auto it: array3){
        cout<< it << ", " ;
    }
}