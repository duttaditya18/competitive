#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map <int, int> mp;
    bool f = true;
    int ans = n - 1, x;
    for(int i = 0; (i < n) && (f); i++)
    {
        //cout << "i: " << i << endl;
        x = 0;
        for(int j = 0; j < i; j++)
        {
            //cout << "j: " << j << endl;
            mp[a[j]]++;
            if(mp[a[j]] > 1)
            {
                f = false;
                break;
            }
            x++;
        }
        if(f)
        {
            for(int j = n - 1; j >= i; j--)
            {
                //cout << "j: " << j << endl;
                mp[a[j]]++;
                if(mp[a[j]] > 1)
                {
                    break;
                }
                x++;
            }
            ans = min(ans, n - x);
        }
        //cout << endl;
        mp.clear();
    }
    cout << ans << endl;
}
