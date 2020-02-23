#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int t; cin >> t;

    while(t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        vector<int> a[26];

        for(int i = 0; i < n; i++) a[s[i] - 'a'].push_back(i);

        // for(int i = 0; i < 26; i++) { cout << char(i + 'a') << " : "; for(auto u : a[i]) cout << u << " "; cout << endl; }

        int cur = -1;
        int ans = 1;
        bool f = true;
        int x;

        for(int i = 0; i < m; i++)
        {
            x = t[i]-'a';
            if(a[x].size() == 0)
            {
                f = false;
                break;
            }

            // cout << t[i] << " " << cur << " : " << upper_bound(a[x].begin(), a[x].end(), cur) - a[x].begin() << endl;
            if((upper_bound(a[x].begin(), a[x].end(), cur) - a[x].begin()) == a[x].size())
            {
                cur = a[x][0];
                ans++;
            }
            else cur = *upper_bound(a[x].begin(), a[x].end(), cur);
        }
        cout << (f ? ans : -1) << "\n";
    }
    return 0;
}
