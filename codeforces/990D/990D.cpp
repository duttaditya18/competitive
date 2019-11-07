#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;

    if(min(a, b) > 1)
    {
        cout << "NO\n";
        return 0;
    }
    if(n == 2 && a == 1 && b == 1)
    {
        cout << "NO\n";
        return 0;
    }
    if(n == 3 && a == 1 && b == 1)
    {
        cout << "NO\n";
        return 0;
    }


    int adj[n + 1][n + 1] = {};

    if(a > b && b == 1)
    {
        for(int i = 2; i <= n - a + 1; i++)
        {
            adj[1][i] = 1;
            adj[i][1] = 1;
        }
    }
    else if(b > a && a == 1)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j) adj[i][j] = 1;

        for(int i = 2; i <= n - b + 1; i++)
        {
            adj[1][i] = 0;
            adj[i][1] = 0;
        }
    }
    else if(a == 1 && b == 1)
    {
        for(int i = 1; i < n; i++)
        {
            adj[i][i + 1] = 1;
            adj[i + 1][i] = 1;
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }
    cout << "\n";
}
