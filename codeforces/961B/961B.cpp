#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    int a[n], t[n];

    // prefixes of all - pra[], prefixes of awake - prb[]
    int pra[n], prb[n] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pra[i] = a[i];
        if(i > 0)
            pra[i] += pra[i - 1];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        if(t[i])
        {
            prb[i] = a[i];
        }
        if(i > 0)
        {
            prb[i] += prb[i - 1];
        }
    }

    /*for(int i = 0; i < n; i++)
    {
        cout << pra[i] << " " << prb[i] << endl;
    }*/

    int c, ma = 0;

    for(int i = 0; i < n - k + 1; i++)
    {
        if(i == 0)
        {
            c = pra[i + k - 1] + prb[n - 1] - prb[i + k - 1];
        }
        else if(i == (n - k))
        {
            c = pra[i + k - 1] - pra[i - 1] + prb[i - 1];
        }
        else
        {
            c = pra[i + k - 1] - pra[i - 1] + prb[i - 1] + prb[n - 1] - prb[i + k - 1];
        }
        ma = max(ma, c);
        //cout << ma << endl;
    }
    cout << ma;
    return 0;
}
