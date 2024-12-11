#include <bits/stdc++.h>
using namespace std;

// this prints all the permutations possible
void usingRecursion(int arr[], int size, int index)
{
    if (index == size)
    {
        // print array
    }

    for (int i = index; i < size; i++)
    {
        swap(arr[index], arr[i]);
        usingRecursion(arr, size, index + 1);
        swap(arr[index], arr[i]);
    }
}

// optimal solution
void nextPermutation(vector<int> arr)
{
    int index = 0;
    int size = arr.size();
    for (int i = size - 2; i > -1; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        cout << "executed";
        return;
    }
    for (int i = size - 2; i > -1; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[index], arr[i]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());

    for (auto it : arr)
    {
        cout << it << " ,";
    }
}

int main()
{
    vector<int> arr = {5, 2, 7, 3, 1, 0};
    nextPermutation(arr);
}