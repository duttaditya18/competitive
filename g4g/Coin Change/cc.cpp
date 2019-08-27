#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c[n];
        for(int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        int x;
        cin >> x;

        int a[x + 1][n] = {};

        for(int i = 0; i < n; i++)
        {
            a[0][i] = 1;
        }

        for(int i = 1; i <= x; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i - c[j] >= 0)
                    a[i][j] += a[i - c[j]][j];
                if(j > 0)
                    a[i][j] += a[i][j - 1];
            }
        }

        cout << a[x][n - 1] << endl;
    }
    return 0;
}
