#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    long long a[n + 1] = {}, prf[n + 1] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prf[i] = a[i] + prf[i - 1];
    }

    long long maxSS[n + 1] = {}, ma = 0;

    for(int i = 1; i <= n - k + 1; i++)
    {
        maxSS[i] = maxSS[i - 1];
        if(prf[i + k - 1] - prf[i - 1] > ma)
        {
            ma = prf[i + k - 1] - prf[i - 1];
            maxSS[i] = i;
        }
    }

    // for(int i = 0; i <= n; i++) cout << maxSS[i] << " "; cout << endl;

    long long maxA = 0, maxB = 0;
    ma = 0;

    for(int i = k + 1; i <= n - k + 1; i++)
    {
        long long cur = prf[i + k - 1] - prf[i - 1];
        if(cur + prf[maxSS[i - k] + k - 1] - prf[maxSS[i - k] - 1] > ma)
        {
            ma = cur + prf[maxSS[i - k] + k - 1] - prf[maxSS[i - k] - 1];
            maxA = maxSS[i - k];
            maxB = i;
        }
    }
    cout << maxA << " " << maxB << endl;
}
