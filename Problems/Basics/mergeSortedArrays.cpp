#include <bits/stdc++.h>
using namespace std;

// WITHOUT USING EXTRA SPACE

// Basically it would been easier if used vector, just insert, we r sticking out without stl, anyway insert also will take some time complexity ig.

void solution1(int arr1[], int arr2[], int size1, int size2)
{
    // dont refer the below array for this

    int left = size1 - 1;
    int right = 0;
    while (left >= 0 && right < size2)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);

    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ,";
    }
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << " ,";
    }

    cout << endl;
}

void swapifGreater(int arr1[], int arr2[], int i, int j)
{
    if (arr1[i] > arr2[j])
    {
        swap(arr1[i], arr2[j]);
    }
}
void solution2(int arr1[], int arr2[], int size1, int size2)
{
    // SHELL SORT

    int len = size1 + size2;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < size1 && right >= size1)
            {
                swapifGreater(arr1, arr2, left, right - size1);
            }
            else if (left >= size1)
            {
                swapifGreater(arr1, arr2, left - size1, right - size1);
            }
            else
            {
                swapifGreater(arr1, arr2, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }

        gap = (gap / 2) + (gap % 2);
    }

    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ,";
    }
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << " ,";
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};

    solution1(arr1, arr2, 5, 5);
    solution2(arr1, arr2, 5, 5);
}