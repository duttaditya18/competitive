#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    string p, s;

    while(t--)
    {
        cin >> p >> s;
        map<char, int> mp;

        bool x = true;

        int psize = p.size();
        int ssize = s.size();
        for(int i = 0; i < psize; i++) mp[p[i]]++;


        for(int i = 0; i <= ssize - psize; i++)
        {
            // cout << i << endl;
            map<char, int> ms;
            for(int j = 0; j < psize; j++)
            {
                ms[s[i + j]]++;
            }
            if(mp == ms)
            {
                cout << "YES\n";
                x = false;
                break;
            }
        }
        if(x) cout << "NO\n";
    }
}
