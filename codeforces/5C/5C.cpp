#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    string s; cin >> s;
    int n = s.size();

    int mx = 0, cn = 0;
    int cx = 0, cb = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            cb++;
        }
        else if(s[i] == ')')
        {
            if(cb > 0)
            {
                // cout << i << " " << cb << " " << cx << "\n";
                cb--;
                cx += 2;
                if(cx > mx)
                {
                    mx = cx;
                    cn = 1;
                }
                else if(cx == mx)
                {
                    cn++;
                }
            }
            else
            {
                cb = 0;
                cx = 0;
            }
        }
    }
    cout << mx << " " << (mx == 0 ? 1 : cn) << "\n";
    return 0;
}
