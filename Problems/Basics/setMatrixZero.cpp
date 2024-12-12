#include <bits/stdc++.h>
using namespace std;

void solution(int (*arr)[4])
{
    // brute force, find each zeroes, mark -1 in their rows and coloumns and another loop to convert -1 to 0s;
    // better: marking the rows and coloumns where zeroes are there in seperate array and another loop to mark them zeroes.
    // optimal:
    int col0 = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j != 0)
                    arr[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    if (arr[0][0] == 0)
    {
        for (int i = 0; i < 4; i++)
            arr[0][i] = 0;
    }

    if (col0 == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            arr[i][0] = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ,";
        }
        cout << endl;
    }
}

int main()
{
    int arr[][4] = {{1, 1, 1, 1}, {1, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 0, 1}};
    solution(arr);
}