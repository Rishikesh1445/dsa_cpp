#include <bits/stdc++.h>
using namespace std;

void unionofArray(vector<int> &array1, vector<int> &array2, vector<int> &array3){
    int i = 0;
    int j = 0;
    array3.emplace_back(array1[i]);
    i++;
    while((i<array1.size()) && (j<array2.size())){
        if(array1[i] <= array2[j]){
            if(array1[i] > array3.back()){
                array3.emplace_back(array1[i]);
            }
            i++;
        }
        if(array2[j] < array1[i]){
            if(array2[j] > array3.back()){
                array3.emplace_back(array2[j]);
                
            }
            j++;
        }
    }

    while((i< array1.size())){
        if(array1[i] > array3.back()){
            array3.emplace_back(array1[i]);
        }
        i++;
    }
    while((j< array2.size())){
        if(array2[j] > array3.back()){
            array3.emplace_back(array2[j]);
        }
        j++;
    }
}

void intersectionArray(vector<int> &array1, vector<int> &array2, vector<int> &array3){
    int i = 0;
    int j = 0;
    while((i < array1.size()) && (j< array2.size())){
        if(array1[i] <= array2[j]){
            if(array1[i] == array2[j]){
                array3.emplace_back(array1[i]);
            }
            i++;
        }
        if(array2[j]< array1[i]){
            if(array2[j] == array1[i]){
                array3.emplace_back(array2[j]);
            }
            j++;
        }
    }
}

int main(){
    vector<int> array1 = {1,3,4,5,5,6};
    vector<int> array2 = {0,2,4,6,6,7,10};
    vector<int> array3;

    //unionofArray(array1, array2, array3);
    intersectionArray(array1, array2, array3);

    for (auto it: array3){
        cout<< it << ", " ;
    }
}

//remainder works only for sorted array