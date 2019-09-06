// Based on Editorial :(

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ma = *max_element(a.begin(), a.end());

    vector<vector<int>> x(ma + 5);
    int xo = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        xo = a[i];
        cnt = 0;
        while(xo > 0)
        {
            x[xo].push_back(cnt);
            xo /= 2;
            cnt++;
        }
    }

    int ans = INFINITY;

    for(int i = 0; i <= ma; i++)
    {
        if(x[i].size() >= k)
        {
            ans = min(ans, accumulate(x[i].begin(), x[i].begin() + k, 0));
        }
    }
    cout << ans << endl;
    return 0;
}
