#include <bits/stdc++.h>
using namespace std;

void solution(int arr[], int size)
{
    unordered_set<int> st;
    int length = 1;
    for (int i = 0; i < size; i++)
    {
        st.emplace(arr[i]);
    }

    for (auto it : st)
    {
        auto prev_element = st.find(it - 1);
        int count = 1;
        if (prev_element == st.end())
        {

            auto tobeFind = it + 1;
            auto next_element = st.find(tobeFind);
            while (next_element != st.end())
            {
                count = count + 1;
                tobeFind = tobeFind + 1;
                next_element = st.find(tobeFind);
            }

            length = max(length, count);
        }
    }

    cout << length << endl;

    // O(3N)
}

int main()
{
    int arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    solution(arr, 9);
}