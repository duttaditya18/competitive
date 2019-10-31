#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        int p[n + 1] = {};

        unordered_map<int, int> m;

        int inp;

        for(int i = 1; i <= n; i++)
        {
            cin >> inp;
            p[i] = inp;
            p[i] += p[i - 1];
        }

        m[0] = 0;

        bool ans = false;
        for(int i = 1; i <= n; i++)
        {
            if(m.find(p[i] - k) != m.end())
            {
                ans = true;
                // cout << p[i]  << " " << p[i] - k << " " << k <<endl;
                cout << m[p[i] - k] + 1 << " " << i;
                break;
            }
            m[p[i]] = i;
        }

        if(!ans) cout << -1;

        cout << endl;
    }
    return 0;
}
