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

        int ans = 0;

        unordered_map<int, int> m;
        m[0]++;
        for(int i = 1; i <= n; i++)
        {
            cin >> inp;
            p[i] = inp;
            p[i] += p[i - 1];
            ans += m[p[i]];
            m[p[i]]++;
        }
        cout << ans << endl;
    }
}
