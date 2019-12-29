#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n + 1] = {};

    int fi, pr, ifx = false;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            if(!ifx)
            {
                ifx = true;
                fi = i;
            }

            if(ifx) a[i] = pr;
            pr = i;
        }
    }
    a[fi] = pr;

    for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
    return 0;
}
