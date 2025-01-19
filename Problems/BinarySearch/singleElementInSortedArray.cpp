#include <bits/stdc++.h>
using namespace std;

//basically we are elimination by checking (even, odd) indices.

int solution(int arr[], int size){
    if (size == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if(arr[size -1] != arr[size -2 ]) return arr[size-2];
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
        if (mid % 2 == 0){
            if (arr[mid] == arr[mid + 1]) left = mid + 1;
            else right = mid - 1;
        } else {
            if (arr[mid] == arr[mid - 1]) left = mid + 1;
            else right = mid - 1;
        }
    }

    return -1;    
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << solution(arr, size) << endl;
    return 0;
}