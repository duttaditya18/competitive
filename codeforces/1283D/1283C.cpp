#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;

    int a[n + 1] = {};
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a, a + n + 1);

    vector<int> d;

    for(int i = 1; i < n; i++)
    {
        d.push_back(a[i + 1] - a[i]);
    }

    vector<int> b;

    return 0;
}
