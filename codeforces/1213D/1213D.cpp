#include <bits/stdc++.h>


using namespace std;

int main(void)
{
    ofstream cout("1213D.out");
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> cnt;
    map<int, int> cstep;

    // Initialize Counters
    int ma = 0;
    for(int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        cstep[a[i]] = 0;
        ma = max(ma, a[i]);
        if(cnt[a[i]] >= k)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    bool f = true;
    int ans = 1e9;

    // Divide the array by 2 and see the answers
    for(int j = 0; j < log2(ma) && (f == true); j++)
    {
        for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
        {
            cout << it->first << " : " << it->second << " : " << cstep[it->first] << "\n";
        }
        cout << endl;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= 0)
            {
                a[i] /= 2;
                cnt[a[i]]++;
                cstep[a[i]]++;
            }
            if(cnt[a[i]] >= k)
            {
                cout << "LSD : " << a[i] << " : " << cnt[a[i]] << " : " << cstep[a[i]]<<  endl;
                ans = min(ans, cstep[a[i]]);
                f = false;
            }
        }
    }
    cout << endl;
    for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    {
        cout << it->first << " : " << it->second << " : " << cstep[it->first] << "\n";
    }
    cout << ans << "\n";
}
