#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n], cur = 1, ma = -1000000005;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if(i >= 1)
        {
            if(a[i - 1] <= a[i])
                cur++;
            else
                cur = 1;
        }
        ma = max(cur, ma);
        //cout << a[i] << " " << a[i - 1] << " " << cur << endl;
    }
    cout << ma << endl;
    return 0;
}
