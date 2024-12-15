#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 1;
    int left = 0, right = 4, top = 0, bottom = 4;
    int arr[5][5] = {{0}};

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = num;
            num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = num;
            num++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bottom][i] = num;
                num++;
            }

            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[i][left] = num;
                num++;
            }
            left++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ,";
        }
        cout << endl;
    }
}