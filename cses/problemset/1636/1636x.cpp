#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

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
            a[i][j] %= 1000000007;
        }
    }

    cout << a[x][n - 1] << endl;


    /*for(int i = 0; i < x + 1; i++)
    {
        cout << i << " : " << a[i][n - 1]<< endl;
    }*/
    return 0;
}
