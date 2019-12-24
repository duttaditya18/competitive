#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        string s; cin >> s;
        int n = s.size();

        int z = 0, o = 0;
        int tz = 0, to = 0, mz = 0, mo = 0;

        int cur = (s[0] == '0' ? 0 : 1);
        if(s[0] == '0') z++;
        else o++;

        for(int i = 1; i < n; i++)
        {
            if(!cur)
            {
                if(s[i] == '0') z++;
                else
                {
                    cur = !cur;
                    tz += z;
                    mz = max(mz, z);
                    z = 0;
                    o = 1;
                }
            }
            else if(cur)
            {
                if(s[i] == '1') o++;
                else
                {
                    cur = !cur;
                    to += o;
                    mo = max(mo, o);
                    z = 1;
                    o = 0;
                }
            }
        }

        to += o;
        tz += z;
        mo = max(mo, o);
        mz = max(mz, o);
        // cout << endl;

        // cout << to << " " << tz << " " << mo << " " << mz << endl;

        cout << min(tz - mz, to - mo) << endl;
    }
}
