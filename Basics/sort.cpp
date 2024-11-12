#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int size){
    for (int i = 0; i< size; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void swap(int arr[], int first, int second){
    if(first == second) return;
    arr[first] = arr[first] + arr[second];
    arr[second] = arr[first] - arr[second];
    arr[first] = arr[first] - arr[second];
}

//Selection Sort
void selection_sort (int arr[], int size){
    for (int i = 0 ; i < (size-1) ; i++){
        int min = i;
        for (int j = i; j< size ; j++){
            if (arr[j] < arr[min] ){
                min =j;
            }
        }
        swap(arr,i, min);
    }
}

//Bubble Sort
void bubble_sort(int arr[], int size){
    for (int i = size -1 ; i>0 ; i--){
        int didswap = 0;
        for (int j = 0 ; j< i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j , j+1 );
                didswap = 1;
            }
        }
        if(didswap == 0){
            break;
        }
    }
}

//Insertion Sort
void insertion_sort(int arr[], int size){
    int j = 0;
    for(int i = 0; i< size ; i++){
        j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr, j-1, j);
            j--;
        }
    }
}

//Merge sort
void merge_arr(vector<int> &arr, int low, int middle, int high){
    vector<int> temp;
    int left = low;
    int right = middle + 1;
    while(left <= middle && right <= high){
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= middle){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = 0; i< temp.size(); i++){
        arr[low + i] = temp[i];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if (low >= high) return;
    int middle = (low + high)/2;
    merge_sort(arr, low, middle);
    merge_sort(arr, middle+1, high);
    merge_arr(arr, low, middle, high);
}

//Quick Sort
int partition(vector<int> &arr, int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    int temp = 0;
    while (i < j){
        while(arr[i] <= arr[pivot] && i <=high) i++;
        while(arr[j] > arr[pivot] && j>=low) j--;
        if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    return j;
}
void quick_sort(vector<int> &arr, int low, int high){
    if (low< high){
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index-1);
        quick_sort(arr, partition_index +1, high);
    }
}

int main(){
    int arr[5] = {1,7,98, 52, 1};
    vector<int> array = {1,7,98,52,1};
    //selection_sort(arr, 5);
    //bubble_sort(arr, 5);
    //insertion_sort(arr, 5);
    //merge_sort(array, 0, 4);
    quick_sort(array, 0, array.size()-1);
    //printarray(arr, 5);
    for (auto it : array){
        cout << it << ", ";
    }
}