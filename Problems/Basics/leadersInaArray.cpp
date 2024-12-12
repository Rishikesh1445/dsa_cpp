#include <bits/stdc++.h>
using namespace std;

void solution(int arr[], int size)
{
    int max = arr[size - 1];
    cout << max << endl;
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            cout << arr[i] << endl;
            max = arr[i];
        }
    }
}

int main()
{
    int arr[] = {10, 22, 12, 3, 0, 6};
    solution(arr, 6);
}