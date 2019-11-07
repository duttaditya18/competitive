#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    int n;
    char c;

    while(t--)
    {
        int ar = 0, ap = 0, as = 0;
        int br = 0, bp = 0, bs = 0;
        cin >> n;
        cin >> br >> bp >> bs;

        int ax[n] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            if(c == 'R'){ ar++; ax[i] = 0; }
            if(c == 'P'){ ap++; ax[i] = 1; }
            if(c == 'S'){ as++; ax[i] = 2; }
        }

        // for(int i = 0; i < n; i++) cout << ax[i] << endl;

        int minP = min(ar, bp);
        int minS = min(ap, bs);
        int minR = min(as, br);
        // cout << minP << " " << minS << " " << minR << endl;
        int x = minP + minS + minR;

        int f = n / 2;
        if(n % 2) f++;
        // cout << x << " " << f << endl;
        if(x >= f)
        {
            cout << "YES\n";
            for(int i = 0; i < n; i++)
            {
                if(ax[i] == 0)
                {
                    if(bp > 0)
                    {
                        cout << "P";
                        bp--;
                        minP--;
                    }
                    else if(bs > minS)
                    {
                        cout << "S";
                        bs--;
                    }
                    else
                    {
                        cout << "R";
                        br--;
                    }
                }
                else if(ax[i] == 1)
                {
                    if(bs > 0)
                    {
                        cout << "S";
                        bs--;
                        minS--;
                    }
                    else if(bp > minP)
                    {
                        cout << "P";
                        bp--;
                    }
                    else
                    {
                        cout << "R";
                        br--;
                    }
                }
                else if(ax[i] == 2)
                {
                    if(br > 0)
                    {
                        cout << "R";
                        br--;
                        minR--;
                    }
                    else if(bs > minS)
                    {
                        cout << "S";
                        bs--;
                    }
                    else
                    {
                        cout << "P";
                        bp--;
                    }
                }
            }
            cout << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
