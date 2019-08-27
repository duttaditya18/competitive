#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int k;
        string s;
        cin >> s >> k;

        if(s.size() <= k)
        {
            cout << 0 << endl;
            continue;
        }

        map<char, int> m;
        vector<int> v;

        for(int i = 0, l = s.size(); i < l; i++)
        {
            m[s[i]]++;
        }
        for(auto const& x : m)
        {
            v.push_back(x.second);
        }
        m.clear();
        int l = v.size(), high;

        /*for(int i = 0; i < l; i++)
        {
            cout << v[i] << endl;
        }
        cout << endl;*/

        for(int i = 0; i < k; i++)
        {
            high = 0;
            for(int j = 0; j < l; j++)
            {
                if(v[j] > v[high])
                {
                    high = j;
                }
            }
            v[high]--;
        }

        int ans = 0;
        for(int i = 0; i < l; i++)
        {
            ans += v[i] * v[i];
            //cout << v[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
