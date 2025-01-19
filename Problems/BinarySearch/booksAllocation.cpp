#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr, int size, int persons){
    if(persons > size) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int sum = 0, count = 1;
        int previousindex = 0;
        for(int i = 0; i < size; i++){
            sum += arr[i];
            if(sum > mid){
                count++;
                sum = arr[i];
                previousindex = i;
            }
        }
        if(count <= persons){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25,46,28,49,24};
    cout << solution(arr, 5, 4) << endl;
}