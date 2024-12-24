#include <bits/stdc++.h>
using namespace std;

int lowerbound(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int answer = size;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] >= target)
        {
            answer = middle;
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    return answer;
}

// Upper Bound:
// everything as above, just remove the equal to sign in if statement

int main()
{
    int arr[] = {1, 4, 5, 6, 7, 7, 8, 10, 15, 20, 25};
    cout << lowerbound(arr, 11, 7) << endl;

    /*
        int lowerBoundIndex = lower_bound(v.begin(), v.end(), target) - arr.begin()
        lower_bound returns an iterator
    */

    // similarly for upper_bound also
}

// floor and ceiling, for >= -> find L.B ; for <= -> another loop
// for first and last occurence, find L.B and U.B-1, with conditions -> lower bound should be equal to target and that index should not be equal to size, otherwise (-1,-1)
//