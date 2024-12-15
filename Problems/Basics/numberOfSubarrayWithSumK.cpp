#include <bits/stdc++.h>
using namespace std;

void solution(int arr[], int size, int target)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        mpp[sum]++;
        if (mpp.find(sum - target) != mpp.end())
        {
            int wtf = mpp.find(sum - target)->second;
            count = count + wtf;
        }
    }

    cout << count << endl;
}

int main()
{
    int arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    solution(arr, 10, 3);
}