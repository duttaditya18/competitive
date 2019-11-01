#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n], sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        unordered_set<int> m[n + 1];
        m[0].insert(0);

        vector<int> v;

        for(int i = 1; i <= n; i++)
        {
            m[i] = m[i - 1];
            for(auto u : m[i - 1])
            {
                m[i].insert(u + a[i - 1]);
            }
        }

        int ans = 0;

        for(auto u : m[n])
        {
            // cout << u.first << endl;
            ans += u;
        }

        cout << ans << endl;
    }
    return 0;
}
