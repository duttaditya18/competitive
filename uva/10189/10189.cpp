#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    // ofstream cout("output.txt");

    int n, m;
    char c;

    int k = 0;

    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        k++;
        int a[n + 2][m + 2] = {};
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> c;
                a[i][j] = (c == '*');
            }
        if(k > 1) cout << "\n";
        cout << "Field #" << k << ":\n";

        int dx[] = {-1, 0, 1};

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j])
                {
                    cout << "*";
                    continue;
                }
                int x = 0;
                for(auto u : dx)
                    for(auto v : dx)
                        x += a[i + u][j + v];
                cout << x;
            }
            cout << "\n";
        }
    }
    return 0;
}
