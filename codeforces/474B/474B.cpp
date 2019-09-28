#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int prf[n + 1];
    prf[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> prf[i];
        if(i > 0) prf[i] += prf[i - 1];
    }

    //for(int i = 0; i < n; i++) cout << prf[i] << " ";
    //cout << endl;

    int q, f;
    cin >> q;

    while(q--)
    {
        cin >> f;

        int l = 0, r = n, m;
        while(r - l > 1)
        {
            m = (l + r) / 2;
            //cout << prf[l] << " " << prf[m] << " " << prf[r] << endl;
            if(prf[m] >= f) r = m;
            else if(prf[m] < f) l = m;
        }
        //cout << prf[l] << " " << prf[r] << endl;

        cout << l + 1 << endl;
    }

    return 0;
}
