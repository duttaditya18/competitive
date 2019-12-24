#include <bits/stdc++.h>

using namespace std;
#define MAXN 150010

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        string s; cin >> s;
        vector<int> v;

        int f = s.find("twone");
        while(f != string::npos)
        {
            s[f + 2] = 'x';
            v.push_back(f + 2);
            f = s.find("twone", f + 1);
        }
        f = s.find("one");
        while(f != string::npos)
        {
            s[f + 1] = 'x';
            v.push_back(f + 1);
            f = s.find("one", f + 1);
        }
        f = s.find("two");
        while(f != string::npos)
        {
            s[f + 1] = 'x';
            v.push_back(f + 1);
            f = s.find("two", f + 1);
        }
        cout << v.size() << endl;
        for(auto u : v) cout << u + 1 << " "; cout << endl;
    }
}
