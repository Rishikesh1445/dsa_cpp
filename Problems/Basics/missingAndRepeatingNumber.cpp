#include <bits/stdc++.h>
using namespace std;

void mathSolution(int arr[], int size)
{
    int n_sum = (size * (size + 1)) / 2;
    int n2_sum = (size * (size + 1) * ((2 * size) + 1)) / 6;
    int x_sum = 0;
    int x2_sum = 0;
    for (int i = 0; i < size; i++)
    {
        x_sum = x_sum + arr[i];
        x2_sum = x2_sum + (arr[i] * arr[i]);
    }
    int x_y = x_sum - n_sum;
    int x2_y2 = x2_sum - n2_sum;
    int x__y = x2_y2 / x_y;
    int x = (x_y + x__y) / 2;
    int y = x__y - x;

    cout << x << " " << y << endl;
}

// no need, hard to keep in mind, just see
// see the video once for logic

void xorSolution(int arr[], int size)
{
    int xr = 0;
    for (int i = 0; i < size; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }
    int bitno = 0;
    while (1)
    {
        if ((xr & (1 << bitno)) != 0)
        {
            break;
        }
        bitno++;
    }
    int one = 0;
    int zero = 0;
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] & (1 << bitno)) != 0)
        {
            one = one ^ arr[i];
        }
        else
        {
            zero = zero ^ arr[i];
        }
    }
    for (int i = 1; i <= size; i++)
    {
        if ((i & (1 << bitno)) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == zero)
        {
            count++;
        }
    }
    if (count == 2)
        cout << zero << " " << one << endl;
    else
        cout << one << " " << zero << endl;
}

int main()
{
    int arr[] = {2, 3, 4, 1, 1};
    mathSolution(arr, 5);
    xorSolution(arr, 5);
}