#include <bits/stdc++.h>
using namespace std;

// u will not get what ur looking for
int main()
{
    set<vector<int>> st;
    set<int> hash;
    vector<int> v = {-1, 0, 1, 2, -1, -4, -2};

    for (int i = 0; i < v.size(); i++)
    {
        hash.clear();
        for (int j = (i + 1); j < v.size(); j++)
        {
            int required = -(v[i] + v[j]);
            auto ele = hash.find(required);
            if (ele != hash.end())
            {
                vector<int> summa = {v[i], v[j], *ele};
                sort(summa.begin(), summa.end());
                st.insert(summa);
            }
            hash.insert(v[j]);
        }
    }

    for (auto it : st)
    {
        for (auto itt : it)
        {
            cout << itt << " ,";
        }
        cout << endl;
    }

    cout << " Second One " << endl;

    int i = 0, j = 0, k = v.size() - 1;
    set<vector<int>> sol;
    sort(v.begin(), v.end());
    while (i < (v.size() - 2))
    {
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {

                vector<int> temp = {v[i], v[j], v[k]};
                sol.insert(temp);
                j++;
                k--;
                while (j < k and v[j - 1] == v[j])
                {
                    j++;
                }
                while (j < k and v[k + 1] == v[k])
                {
                    k--;
                }
            }
        }
        i++;
        while (v[i - 1] == v[i])
        {
            i++;
        }
        j = i + 1;
        k = v.size() - 1;
    }

    for (auto it : sol)
    {
        for (auto itt : it)
        {
            cout << itt << " ,";
        }
        cout << endl;
    }
}