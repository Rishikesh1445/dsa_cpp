#include <bits/stdc++.h>
using namespace std;

//this involves non sorted array with duplicates.
// an return any one of the indies of peak element incase of multiple peak elements.
int solution(int arr[], int size){
    if(size == 1){
        return 0;
    }
    if(arr[0] > arr[1]){
        return 0;
    }
    if(arr[size-1] > arr[size-2]){
        return size-1;
    }
    int left = 1;
    int right = size-2;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] < arr[mid-1]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return -1;

}

int main(){
    int arr[] = {1,2,5,2,1};
    cout<<solution(arr, 5) << endl;
    return 0;
}