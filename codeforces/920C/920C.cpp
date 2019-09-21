// fuck you arrays

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int tmx, psn[n + 1] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> tmx;
        psn[tmx] = i - tmx + 1;
    }
    char tm;
    int prf[n] = {};
    for(int i = 0; i < n - 1; i++)
    {
        cin >> tm;
        if(tm == '0') prf[i + 1] = 0;
        else if(tm == '1') prf[i + 1] = 1;
        if(i > 0)
            prf[i + 1] += prf[i];
    }
    /*for(int i = 0; i <= n; i++)
    {
        cout << psn[i] << " " << prf[i] << endl;
    }*/
    bool x = true;
    for(int i = 1; i < n + 1; i++)
    {
        if(psn[i] == 0) continue;
        else if(psn[i] != 0)
        {
            if(prf[i + psn[i] - 1] - prf[i - 1] == psn[i]) continue;
            else
            {
                x = false;
                break;
            }
        }
    }

    cout << (x ? "YES\n" : "NO\n");

}
