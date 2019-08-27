#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, l, r;
    cin >> n >> l >> r;

    int s = 1, mi = 0, ma = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < (n - l + 1))
            mi += s;
        else
        {
            s *= 2;
            mi += s;
        }
    }
    s = 1;
    for(int i = 0; i < n; i++)
    {
        if(i < (r - 1))
        {
            ma += s;
            s *= 2;
        }
        else
        {
            ma += s;
        }
    }
    cout << mi << " " << ma << endl;
    return 0;
}
