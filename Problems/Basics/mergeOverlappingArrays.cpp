#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> ans;

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (ans.empty() || v[i][0] > ans.back()[1])
        {
            ans.push_back(v[i]);
        }
        else
        {
            if (v[i][0] < ans.back()[1] && v[i][1] > ans.back()[1])
            {
                ans.back()[1] = v[i][1];
            }
        }
    }

    for (auto it : ans)
    {
        for (auto itt : it)
        {
            cout << itt << " ,";
        }
        cout << endl;
    }
}