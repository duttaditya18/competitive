#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    // ofstream cout("output.txt");

    int t, n; cin >> t;
    char c;

    for(int k = 1; k <= t; k++)
    {
        cin >> n;
        int a[n + 1] = {};
        for(int i = 1; i <= n; i++)
        {
            cin >> c;
            a[i] = (c == '.');
        }

        vector<int> v;

        int cur = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] != a[i - 1])
            {
                v.push_back(cur);
                cur = 1;
            }
            else cur++;
        }
        v.push_back(cur);

        cur = a[1];

        int c = v.size();
        int ans = 0;
        for(int i = 0; i < c; i++)
        {
            // cout << i << " " << v[i] << " " << v[i] % 3 << " " << v[i + 2] % 3 << " " << v[i + 1] << endl;
            if(cur)
            {
                if(i < c - 2)
                {
                    if((v[i] % 3 == 1) && (v[i + 2] % 3 >= 1) && (v[i + 1] == 1))
                    {
                        // cout << "c " << i << endl;
                        ans += (v[i] / 3) + 1;
                        v[i + 2]--;
                        cur = !cur;
                        continue;
                    }
                }

                ans += (v[i] / 3) + (v[i] % 3 != 0);
            }
            // cout << i << " " << cur << endl;
            cur = !cur;
        }
        cout << "Case " << k << ": "<< ans << "\n";
        // for(auto u : v) cout << u << " ";
        // cout << "\n";
    }

    return 0;
}
