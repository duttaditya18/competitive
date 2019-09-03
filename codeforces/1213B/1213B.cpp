#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mi = INFINITY, ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] > mi)
            {
                ans++;
            }
            else if(a[i] != mi)
            {
                mi = a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
