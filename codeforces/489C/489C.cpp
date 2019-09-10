// WA

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, s;
    cin >> m >> s;

    int x = (s / 9);
    bool flag = false;
    if(s % 9)
    {
        flag = true;
        if(m <= x)
        {
            cout << -1 << " " << -1 << endl;
            return 0;
        }
    }
    else
    {
        if(m < x)
        {
            cout << -1 << " " << -1 << endl;
            return 0;
        }
    }
    string small = "", big = "";

    if(!(m == 1 && s == 0))
    {
        if(m <= s && s != 0)
        {
            int cp = s;
            int call = x;
            if(flag)
            {
                call++;
            }
            for(int i = 0; i < m - call; i++)
            {
                small += "1";
            }
            cp -= (m - call);
            if(cp % 9)
            {
                small += to_string(cp % 9);
                call--;
            }
            for(int i = 0; i < call; i++)
            {
                small += "9";
            }
        }
        else
        {
            small = "-1";
        }

        if(s != 0)
        {
            for(int i = 0; i < x; i++)
            {
                big += "9";
            }
            if(flag)
            {
                big += to_string(s % 9);
            }
            for(int i = big.size(); i < m; i++)
            {
                big += "0";
            }
        }
        else
        {
            big = "-1";
        }
    }
    else
    {
        small = "0";
        big = "0";
    }
    cout << small << " " << big;
}
