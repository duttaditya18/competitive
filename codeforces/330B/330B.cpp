#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int s[n + 1] = {};

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        s[a] = true;
        s[b] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!s[i])
        {
            cout << n - 1 << endl;
            for(int j = 1; j <= n; j++)
            {
                if(i != j) cout << i << " " << j << endl;
            }
            break;
        }
    }
    return 0;
}
