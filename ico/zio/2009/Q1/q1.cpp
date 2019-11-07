#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    while(cin >> n)
    {
        int g[n + 1] = {}, f[n + 1] = {}, h[n + 1] = {};
        g[0] = 0; g[1] = 0; f[0] = 1; f[1] = 1, h[0] = 1; h[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + h[i - 2] + (2 * g[i - 1]);
            g[i] = f[i - 2] + g[i - 1];
            h[i] = f[i - 1] + (2 * g[i - 1]);
        }
        cout << f[n] << endl;
    }

}
