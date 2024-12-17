#include <bits/stdc++.h>
using namespace std;

// Merge sort
int merge_arr(vector<int> &arr, int low, int middle, int high)
{
    int county = 0;

    vector<int> temp;
    int left = low;
    int right = middle + 1;
    while (left <= middle && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            county += (middle - left + 1); // ---> just this one line added
            right++;
        }
    }
    while (left <= middle)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }

    return county;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int county = 0;

    if (low >= high)
        return county;
    int middle = (low + high) / 2;
    county += merge_sort(arr, low, middle);
    county += merge_sort(arr, middle + 1, high);
    county += merge_arr(arr, low, middle, high);

    return county;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    int county = merge_sort(arr, 0, arr.size() - 1);

    cout << county << endl;
}