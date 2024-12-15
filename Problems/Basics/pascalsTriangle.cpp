#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int r = 5;

    int x = 1;
    for (int i = 0; i < r; i++)
    {
        x = x * (n - i);
        x = x / (i + 1);
    }

    cout << x << endl;

    x = 1;
    int tobemultipled = 1;
    cout << x << " ,";
    for (int i = 1; i < (n + 1); i++)
    {
        tobemultipled = (n + 1 - i);
        x *= tobemultipled;
        x = x / i;
        cout << x << " ,";
    }

    // Striver solution was to run the above loop itself for each row. Optimal is O(n^2)
    // This is another solution below with same time complexity but takes up space so much.

    // somehow assign zero here for all vec

    vector<vector<int>> vec = {{0}};

    for (int i = 0; i < n + 1; i++)
    {
        vec[i].push_back(1);
        for (int j = 1; j <= i; j++)
        {
            if (j < i)
            {
                vec[i].push_back(vec[i - 1][j - 1] + vec[i - 1][j]);
            }
            else
            {
                vec[i].push_back(1);
            }
        }
    }

    for (auto it : vec)
    {
        for (auto itt : it)
        {
            cout << itt << " ,";
        }
        cout << endl;
    }
}