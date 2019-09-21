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

        int pref[n] = {};
        long long temp;
        cin >> temp;
        pref[0] = ((temp % k) + k) % k;
        for(int i = 1; i < n; i++)
        {
            cin >> temp;
            pref[i] = (temp % k);
            pref[i] += pref[i - 1];
            pref[i] = ((pref[i] % k) + k) % k;
        }

        /*for(int i = 0; i < n; i++)
            cout << pref[i] << endl;*/

        unordered_map<int, int> mp;

        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            if(pref[i] == 0)
            {
                mx = i + 1;
            }
            else if(!mp.count(pref[i]))
            {
                mp[pref[i]] = i;
            }
            else if(mp.count(pref[i]))
            {
                mx = max(mx, i - mp[pref[i]]);
            }
        }
        cout << mx << endl;
    }
    return 0;
}
