#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 1, 1, 1, 3, 4, 3, 3, 2, 2};
    vector<int> ls;
    map<int, int> mpp;
    int mini = (int)(v.size() / 3) + 1;
    for (int i = 0; i < (v.size()); i++)
    {
        mpp[v[i]]++;
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }

    sort(ls.begin(), ls.end());

    for (auto it : ls)
    {
        cout << it;
    }

    // optimal solution --  same to as moore voting algo but with n/3
    int count1 = 0, count2 = 0;
    int el1 = 0, el2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (count1 == 0 and v[i] != el2)
        {
            el1 = v[i];
            count1++;
        }
        else if (count2 == 0 and v[i] != el1)
        {
            el2 = v[i];
            count2++;
        }
        else if (el1 == v[i])
        {
            count1++;
        }
        else if (el2 == v[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    int check1 = 0, check2 = 0;
    for (int j = 0; j < v.size(); j++)
    {
        if (el1 == v[j])
        {
            check1++;
        }
        if (el2 == v[j])
        {
            check2++;
        }
    }
    if (check1 > 3)
    {
        cout << el1 << endl;
        ;
    }
    if (check2 > 3)
    {
        cout << el2 << endl;
        ;
    }
}