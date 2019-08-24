// END ME

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
    sort(c, c + n);

    int a[x + 1][n] = {};

    for(int i = 1; i <= x; i++)
    {
        cout << "i: " << i << endl;
        for(int j = 0; j < n; j++)
        {
            cout << "  c[j]: " << c[j] << endl;
            if(c[j] < i)
            {
                for(int k = 0; k <= j - k; k++)
                {
                    cout << "    c[k]: " << c[k] << endl;
                    a[i][j] += a[i - 1][k];
                }
            }
            if(c[j] == i)
            {
                cout << "bop" << endl;
                a[i][j]++;
            }
        }
        cout << endl;
    }

    for(int i = 0; i < x + 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
