#include <bits/stdc++.h>
using namespace std;

//time complexity is O(size + shiftby) i.e O(n +d)
//space complexity is O(d)
void shiftArray(int arr[], int size, int shiftby){
    shiftby = shiftby%size;
    int temp[shiftby];
    for (int i = 0; i<shiftby; i++){
        temp[i] = arr[i];
    }

    for(int j = shiftby; j<size; j++){
        arr[j - shiftby] = arr[j];
    }

    for(int k = (size - shiftby); k<size; k++){
        arr[k] = temp[k - size + shiftby];
    }
}

//TC is O(2n); higher than last one
//SC is O(1);
void shiftarrayOptimal(int arr[], int size, int d){
    reverse(arr, arr+d);
    reverse(arr+d+1, arr+size);
    reverse(arr, arr+size);
}

void reversewithoutstl(int arr[], int start, int end){
    while(start <=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    //shiftArray(arr, 5, 4);

    shiftarrayOptimal(arr, 5,3);
    for (auto it : arr){
        cout << it << ", ";
    }
}