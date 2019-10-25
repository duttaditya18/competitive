// IDK

#include <bits/stdc++.h>

using namespace std;

#define INF

int main(void)
{
    int n;
    cin >> n;

    int x;
    int twos[n + 1][n + 1] = {};
    int fives[n + 1][n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            if(min(twos[i - 1][j], fives[i - 1][j]) < min(twos[i][j - 1], fives[i][j - 1]))
            {
                twos[i][j] = twos[i - 1][j];
                fives[i][j] = fives[i - 1][j];
            }
            else if(min(twos[i - 1][j], fives[i - 1][j]) > min(twos[i][j - 1], fives[i][j - 1]))
            {

                twos[i][j] = twos[i][j - 1];
                fives[i][j] = fives[i][j - 1];
            }
            else if(max(twos[i - 1][j], fives[i - 1][j]) <= max(twos[i][j - 1], fives[i][j - 1]))
            {
                twos[i][j] = twos[i - 1][j];
                fives[i][j] = fives[i - 1][j];
            }
            else if(max(twos[i - 1][j], fives[i - 1][j]) > max(twos[i][j - 1], fives[i][j - 1]))
            {
                twos[i][j] = twos[i][j - 1];
                fives[i][j] = fives[i][j - 1];
            }
            twos[i][j] += __builtin_ctz(x & ~(x - 1));
            while(!(x % 5))
            {
                if(!(x % 5)) fives[i][j]++;
                x /= 5;
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << twos[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << fives[i][j] << " ";
        }
        cout << "\n";
    }

    cout << min(twos[n][n], fives[n][n]) << "\n";
}
