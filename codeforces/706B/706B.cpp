#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    a[n + 1] = INT_MAX;

    //for(int i = 0; i < n; i++) cout << a[i] << " ";
    //cout << endl;

    int q, x;
    cin >> q;

    while(q--)
    {
        cin >> x;
        int l = 0, r = n + 1, m;
        while(r - l > 1)
        {
            m = (l + r) / 2;
            //cout << a[l] << " " << a[m] << " " << a[r] << endl;
            if(a[m] <= x) l = m;
            else if(a[m] > x) r = m;
        }
        //cout << a[l] << " " << a[r] << endl;

        cout << l << endl;
    }
    return 0;
}
