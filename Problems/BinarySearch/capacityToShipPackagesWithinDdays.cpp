#include <bits/stdc++.h>
using namespace std;

int checkIfPossible(int arr[], int size, int days, int capacity){
    int daystook = 0;
    int sum = 0;
    for(int i = 0 ; i<size; i++){
        if((sum + arr[i]) <= capacity){
            sum += arr[i];
        }
        else{
            daystook++;
            sum = arr[i];
        }
    }
    if((sum <= capacity) and (sum > 0)){
        daystook++;
    }

    return (daystook<=days);
}

int solution(int arr[], int size, int days){
    int low = arr[size-1]; //assuming sorted and taking max one;
    int high = (low*(low + 1))/2;
    int ans = -1;
    if(size == 1){
        return arr[0];
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        if(checkIfPossible(arr, size, days, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << solution(arr, 10, 5) << endl;
}