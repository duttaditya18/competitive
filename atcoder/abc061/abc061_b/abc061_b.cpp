#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int deg[n + 1] = {};

    int a, b;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        deg[a]++; deg[b]++;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << deg[i] << endl;
    }
    return 0;
}
