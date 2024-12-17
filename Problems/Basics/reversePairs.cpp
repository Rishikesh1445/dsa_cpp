#include <bits/stdc++.h>
using namespace std;

// Merge sort
void merge_arr(vector<int> &arr, int low, int middle, int high)
{
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
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = 0; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - mid + 1);
    }
    return cnt;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int county = 0;
    if (low >= high)
        return county;
    int middle = (low + high) / 2;
    merge_sort(arr, low, middle);
    merge_sort(arr, middle + 1, high);
    county += countPairs(arr, low, middle, high);
    merge_arr(arr, low, middle, high);

    return county;
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    int county = merge_sort(arr, 0, arr.size() - 1);

    cout << county << endl;
}