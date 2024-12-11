#include <bits/stdc++.h>
using namespace std;

void solution(int arr[], int size)
{
    int i = 0;
    int j = 1;
    int sol[size];
    for (int k = 0; k < size; k++)
    {
        if (arr[k] < 0)
        {
            sol[j] = arr[k];
            j += 2;
        }
        else
        {
            sol[i] = arr[k];
            i += 2;
        }
    }

    for (auto it : sol)
    {
        cout << it << " ,";
    }
}

int main()
{
    int arr[] = {3, 1, -2, -5, 2, -4};
    solution(arr, 6);
}

/*if the number of positive and negative aren't equal,
fall back to brute force method, that is postive and negative seperate array*/