#include <bits/stdc++.h>

using namespace std;

int a[13][23];

int main(void)
{
    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");

    int k, n, c; cin >> k >> n;

    for(int i = 0; i < k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> c;
            a[i][c] = j;
        }
    }

    // for(int i = 0; i < k; i++) { for(int j = 1; j <= n; j++) cout << a[i][j] << " "; cout << endl; }

    int an = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int b = 0;
            bool g = true;
            for(int f = 0; f < k; f++)
            {
                if(f == 0)
                {
                    b = (a[f][i] - a[f][j]) / abs(a[f][i] - a[f][j]);
                    continue;
                }
                if(b != (a[f][i] - a[f][j]) / abs(a[f][i] - a[f][j]))
                {
                    g = false;
                    break;
                }
            }
            if(g) an++;
        }
    }
    cout << an << "\n";
}
