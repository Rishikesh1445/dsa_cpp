#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int target = 6;

    map<int, int> find;
    find[0]++;
    int temp = 0;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        temp = temp ^ arr[i];
        find[temp]++;
        int toFind = temp ^ target;
        auto it = find.find(toFind);
        if (it != find.end())
        {
            count = count + it->second;
        }
    }
    cout << count << endl;
}