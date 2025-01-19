#include <bits/stdc++.h>
using namespace std;

int solution(int arr[], int size, int cows){
    int low = 1;
    int high = arr[size-1] - arr[0];
    int ans = 0;
    while(low <=high){
        int mid = low + (high - low)/2;
        int count = 1;
        int lastcowindex = 0;
        for (int i = 1; i< size; i++){
            if (arr[i] - arr[lastcowindex] >= mid){
                count++;
                lastcowindex = i;
            }
        }
        if(count < cows){
            high = mid - 1;
        }else{
            if(count == cows){
                ans = max(mid, ans);
            }
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int arr[] = {0,3,4,7,9,10};
    //if not sorted, sort it first.

    cout << solution(arr, 6, 4) << endl;
}