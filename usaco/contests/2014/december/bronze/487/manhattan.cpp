#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream cin("marathon.in");
    ofstream cout("marathon.out");
    int n;
    cin >> n;
    int a[n][2];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int m[n - 1];
    int full = 0;
    for(int i = 0; i < n - 1; i++)
    {
        m[i] = abs(a[i][0] - a[i + 1][0]) + abs(a[i][1] - a[i + 1][1]);
        full += m[i];
    }
    int mi = INFINITY;
    for(int i = 1; i < n - 1; i++)
    {
        mi = min(mi, (full - m[i - 1] - m[i] + (abs(a[i - 1][0] - a[i + 1][0]) + abs(a[i - 1][1] - a[i + 1][1]))));
    }
    cout << mi;
}
