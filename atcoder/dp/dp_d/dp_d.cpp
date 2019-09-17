#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    int w[n], v[n];

    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

    long long a[x + 1] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = x; j >= 1; j--)
        {
            if(j >= w[i])
            {
                a[j] = max(a[j], a[j - w[i]] + v[i]);
            }
        }
    }
    cout << a[x] << endl;
    return 0;
}
