#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int a[n], b[n];

        // 1 = +ve, 2 = -ve
        for(int i = n - 1; i >= 0; i--) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        // for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        // for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl << endl;

        unordered_map<int, int> ma, mb;

        ma[0] = 0;
        mb[0] = 0;

        int ca = 0, cb = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == 1) ca++;
            else ca--;

            if(ma.find(ca) == ma.end()) ma[ca] = i + 1;

            if(b[i] == 1) cb++;
            else cb--;
            // cout << ca << " " << cb << endl;

            if(mb.find(ca) == mb.end()) mb[cb] = i + 1;
        }

        int td = ca + cb;

        cout << td << endl<< endl;

        bool x = true;

        for(auto u : ma) cout << u.first << " " << u.second << endl; cout << endl;
        for(auto u : mb) cout << u.first << " " << u.second << endl; cout << endl;

        int ans = INT_MAX;

        for(auto u : ma)
        {
            if(mb.find(td - u.first) != mb.end())
            {
                // cout << td - u.first << " " << mb[td - u.first] << endl;
                ans = min(ans, ma[u.first] + mb[td - u.first]);
            }
        }
        cout << ans << endl;
    }
}
