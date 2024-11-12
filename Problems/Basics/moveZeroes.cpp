#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int first, int second){
    if(first == second) return;
    arr[first] = arr[first] + arr[second];
    arr[second] = arr[first] - arr[second];
    arr[first] = arr[first] - arr[second];
}
//TC - O(N)
//SC - O(1)
void moveZeroes(int arr[], int size){
    int i = 0;
    int j = -1;
    for(i = 0; i<size; i++){
        if (arr[i] == 0){
            j=i;
            break;
        }
    }
    for(i = j+1 ; i<size ; i++){
        if(arr[i] != 0) {
            swap(arr, j,i);
            j++;
        }
    }
}

int main(){
    int arr[] = {1,0,1};
    moveZeroes(arr, 3);
    for (auto it: arr) cout<< it << ", " ;
}

//EVEN MORE BETTER SOLUTION IN LEETCODE, CHECK