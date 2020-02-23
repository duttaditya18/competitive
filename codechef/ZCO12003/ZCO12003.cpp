#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int x;
    vector<int> v;
    int mad = 0;

    int ccd = 0, mcd = 0, icd = 0;
    int cbd = 0, mbd = 0, ibd = 0;
    for(int i = 0; i < n; i++)
    {
        if(!(v.size()))
        {
            x = a[i];
            v.push_back(1);
        }
        if(x == 1)
        {
            if(a[i] == 2)
            {
                if(v[v.size() - 1] == 1) v.pop_back();
                v[v.size() - 1]--;
            }
            else if(a[i] == 1)
            {
                v[v.size() - 1]++;
            }
            else if(a[i] == 3)
            {
                x = a[i];
                v.push_back(1);
            }
        }
        else if(x == 3)
        {
            if(a[i] == 4)
            {
                if(v[v.size() - 1] == 1) v.pop_back();
                v[v.size() - 1]--;
            }
            else if(a[i] == 3)
            {
                v[v.size() - 1]++;
            }
            else if(a[i] == 1)
            {
                x = a[i];
                v.push_back(1);
            }
        }

        if(icd == 0 && a[i] == 1)
        {
            icd = 1;
            ccd = 1;
        }
        else if(icd > 0)
        {
            ccd++;
            if(a[i] == 1)
            {
                icd++;
            }
            else if(a[i] == 2)
            {
                icd--;
            }
        }

        if(ibd == 0 && a[i] == 3)
        {
            ibd = 1;
            cbd = 1;
        }
        else if(ibd > 0)
        {
            cbd++;
            if(a[i] == 3)
            {
                ibd++;
            }
            else if(a[i] == 4)
            {
                ibd--;
            }
        }

        mcd = max(mcd, ccd);
        mbd = max(mbd, cbd);
        mad = max(mad, int(v.size()));
    }
    cout << mad << " " << mcd << " " << mbd << "\n";

    return 0;
}
