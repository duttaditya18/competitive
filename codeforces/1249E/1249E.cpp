#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, c;
    cin >> n >> c;
    int a[n - 1], b[n - 1];
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
        b[i] += c;
    }

    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        cout << cur << " ";
        cur += min(a[i], b[i]);
    }
}
