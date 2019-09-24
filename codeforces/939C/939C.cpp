// WA :'

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n], prf[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        prf[i] = a[i];
        if(i > 0) prf[i] += prf[i - 1];
    }

    int s, f;
    cin >> s >> f;

    int x = f - s;

    int msf = 0, mf = 0, mind = 0;

    for(int i = 0; i < n; i++)
    {
        msf = 0;
        if(i == 0)
        {
            msf = prf[i + x - 1];
        }
        else if(i < (n - (x) + 1))
        {
            msf = prf[i + x - 1] - prf[i - 1];
        }
        else if(i >= (n - (x) + 1))
        {
            msf = prf[n - 1] - prf[i - 1] + prf[i - (n - x) - 1];
        }
        //cout << i << " : " << msf << endl;
        if(msf > mf)
        {
            mf = msf;
            mind = i;
        }
    }

    //cout << mf << " " << mind << endl;

    int ans = (((s - mind) % n) + n) % n;
    if(ans == 0) ans = n;

    cout << ans << endl;


    return 0;
}
