#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k; cin >> n >> k;

    vector<int> v;

    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    // for(int i = 0; i < n; i++) cout << v[i] << " "; cout << endl;

    int r = lower_bound(v.begin(), v.end(), k) - v.begin() - 1;

    long long ans = 0;
    for(int i = 0; i < r; i++)
    {
        while(v[i] + v[r] >= k) r--;

        if(i < r) ans += (1ll * r - i);

        // cout << i << " " << r << endl;
    }

    cout << ans << endl;
}
