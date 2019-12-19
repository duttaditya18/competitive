#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int n = s.size();

    string sx = "hello";
    int nx = sx.size();

    int cur = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == sx[cur]) cur++;
        else continue;

        if(cur == nx)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
