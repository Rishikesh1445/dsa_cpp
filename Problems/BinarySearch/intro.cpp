#include <bits/stdc++.h>
using namespace std;

// Always appliable when sorted
int iterativeSolution(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (target == arr[middle])
        {
            return middle;
        }
        else if (arr[middle] > target)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    return -1;
}

int recursiveSolution(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (target > arr[mid])
        return recursiveSolution(arr, mid + 1, high, target);
    return recursiveSolution(arr, low, mid - 1, target);
}

// overflow case:
//  mid = low + (high-low)/2;

int main()
{
    int arr[] = {1, 4, 5, 10, 15, 19, 20, 25, 50, 52};
    int solution = iterativeSolution(arr, 10, 5);
    // solution = recursiveSolution(arr, 0, 9, 5);
    cout << solution << endl;
}