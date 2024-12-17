#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int arr[n] = {};
    int ans = INT_MIN;
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre = pre * arr[i];
        suf = suf * arr[n - i];
        ans = max(ans, max(pre, suf));
    }
}