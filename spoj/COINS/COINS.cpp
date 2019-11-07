#include <bits/stdc++.h>

using namespace std;

#define MAX 100000000

long long dp[MAX + 1];

long long rec(long long n)
{
    if(n <= MAX) return dp[n];
    return max(rec(n / 2) + rec(n / 3) + rec(n / 4), n);
}

int main(void)
{
    dp[0] = 0;
    for(long long i = 1; i <= MAX; i++)
    {
        dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], i);
    }

    long long n;
    while(cin >> n)
    {
        cout << rec(n) << endl;
    }
}
