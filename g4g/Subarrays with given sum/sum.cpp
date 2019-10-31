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

        int inp, p[n + 1] = {};

        for(int i = 1; i <= n; i++)
        {
            cin >> inp;
            p[i] = inp;
            p[i] += p[i - 1];
        }

        int k;
        cin >> k;

        unordered_multiset<int> m;

        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            ans += m.count(p[i] - k);
            m.insert(p[i]);
        }
        cout << ans << endl;
    }
}
