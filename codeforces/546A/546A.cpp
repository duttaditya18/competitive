#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long k, n, w;
    cin >> k >> n >> w;

    long long x = ((w) * (w + 1) / 2) *  k;
    cout << max(x - n, 0LL);
    return 0;
}
