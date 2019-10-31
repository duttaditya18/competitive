#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    int a[n];

    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    // cur, sum, min, max
    queue<tuple<int, int, int, int>> q;
    int cur, sum, mi, ma;

    q.push(make_tuple(0, 0, INT_MAX, 0));

    while(!q.empty())
    {
        cur = get<0>(q.front());
        sum = get<1>(q.front());
        mi = get<2>(q.front());
        ma = get<3>(q.front());

        // cout << cur << " " << sum << " " << mi << " " << ma;
        q.pop();
        if(l <= sum && sum <= r && ma - mi >= x and cur == n)
        {
            ans++;
            // cout << "f";
        }
        // cout << endl;

        if(cur < n)
        {
            q.push(make_tuple(cur + 1, sum + a[cur], min(mi, a[cur]), max(ma, a[cur])));
            q.push(make_tuple(cur + 1, sum, mi, ma));
        }

    }

    cout << ans << endl;
}
