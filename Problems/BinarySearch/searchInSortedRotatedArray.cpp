#include <bits/stdc++.h>
using namespace std;

// without duplicacy
int solution1(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == target)
            return middle;
        else if (arr[low] <= arr[middle])
        {
            if ((arr[low] <= target) and (target <= arr[middle]))
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        else
        {
            if ((arr[middle] <= target) and target <= arr[high])
            {
                low = low + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
    }
    return -1;
}

// with duplicacy
int solution2(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == target)
            return middle;
        else if((arr[low] == arr[middle]) and( arr[middle] == arr[high])){
            low = low + 1;
            high = high -1;
        }
        else if (arr[low] <= arr[middle])
        {
            if ((arr[low] <= target) and (target <= arr[middle]))
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        else
        {
            if ((arr[middle] <= target) and target <= arr[high])
            {
                low = low + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << solution1(arr, 9, 1) << endl;
    int arrr[] = {7,7,7,8,1,2,2,3,3,3,4,4};
    cout << solution2(arrr, 12, 1) << endl;
}