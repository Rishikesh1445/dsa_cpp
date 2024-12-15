#include <bits/stdc++.h>
using namespace std;

void solution(vector<vector<int>> arr)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }

    for (auto it : arr)
    {
        for (auto itt : it)
        {
            cout << itt << " ,";
        }

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    solution(arr);
}