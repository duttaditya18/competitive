#include <bits/stdc++.h>

using namespace std;

long long s[51], p[51];

long long f(int n, long long x)
{
    if(n == 0)
    {
        return (x <= 0 ? 0 : 1);
    }
    if(x <= 1 + s[n - 1]) return f(n - 1, x - 1);

    return (1 + p[n - 1] + f(n - 1, x - s[n - 1] - 2));
}

int main(void)
{
    s[0] = 1;
    p[0] = 1;
    int n;
    long long x;
    cin >> n >> x;

    for(int i = 1; i <= n; i++)
    {
        s[i] = (2 * s[i - 1]) + 3;
        p[i] = (2 * p[i - 1]) + 1;
        // cout << i << " " << s[i] << " " << p[i] << endl;
    }

    cout << f(n , x) << endl;
}
