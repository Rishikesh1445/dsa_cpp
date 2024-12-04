#include <bits/stdc++.h>
using namespace std;

/*Brute force method:
    Generate all possible sub arrays in an array, check the sum and length
 */

void bestSolution(int arr[], int k, int size)
{
    map<int, int> mpp;
    int length = 0;
    int sum = 0;
    mpp[0] = -1;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        if (sum != 0 && arr[i] != 0)
        {
            mpp[sum] = i;
        }
        if (sum == k || sum > k)
        {
            auto it = mpp.find(sum - k);
            if (it == mpp.end())
                continue;
            length = max(length, (i - (it)->second));
        }
    }

    cout << "length is: " << length << endl;
}

void optimalSolution(int arr[], int k, int size)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int length = 0;

    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        if (sum == k)
        {
            length = max(length, (i - j + 1));
        }
        while (sum > k)
        {
            sum = sum - arr[j];
            if (sum == k)
            {
                length = max(length, (i - j + 1));
            }
            j++;
        }
    }

    cout << "length is: " << length << endl;
}

int main()
{
    int k = 3;
    int arr[] = {-1, 2, 0, 3, 1, 1, 1, 0, 0, 0, 4, 2, 3};
    bestSolution(arr, 6, 13);
    optimalSolution(arr, 6, 13);
}