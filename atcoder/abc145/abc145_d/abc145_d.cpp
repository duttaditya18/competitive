#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000001

int dp[MAXN][MAXN];

int rec(int x, int y)
{
    return x + y;
}

int main(void)
{
    int x, y;
    cin >> x >> y;

    cout << rec(x, y) << endl;
    return 0;
}
