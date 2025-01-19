#include <bits/stdc++.h>
using namespace std;

int solution(int arr[], int size){
    int low = 0;
    int high = size-1;
    int ans = INT_MAX;
    while(low < high){
        int middle = (high + low)/2;
        
        if(arr[low] <= arr[middle]){
            ans = min(ans, arr[low]);
            low = middle + 1;
        }
        else{
            ans = min(ans , arr[middle]);
            high = middle -1;
        }
    }

    return ans;
}

int main(){
    int arr[] = {7,8,9,9,1,1,2,3,4};
    cout << solution(arr, 9) << endl;
}