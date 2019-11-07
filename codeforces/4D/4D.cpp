#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int, int> &t1, tuple<int, int, int> &t2)
{
    if(get<0>(t1) != get<0>(t2)) return (get<0>(t1) < get<0>(t2));
    return (get<1>(t1) < get<1>(t2));
}

int main(void)
{
    int n, w, h, a, b;
    cin >> n >> w >> h;
    vector<tuple<int, int, int>> v;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_tuple(a, b, i + 1));
    }

    sort(v.begin(), v.end(), comp);

    // cout << endl; for(int i = 0; i < n; i++) cout << i + 1 << " " << get<0>(v[i]) << " " << get<1>(v[i]) << endl; cout << endl;

    int dp[n + 1] = {};
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        // cout << i << " " << get<0>(v[i - 1]) << " " << get<1>(v[i - 1]) << " " << w << " " << h << endl;
        dp[i] = max(dp[i], dp[i - 1]);
        if(get<0>(v[i - 1]) > w && get<1>(v[i - 1]) > h) dp[i] = max(dp[i], 1);
        else continue;
        for(int j = 1; j < i; j++)
        {
            if((get<0>(v[j - 1]) < get<0>(v[i - 1])) && (get<1>(v[j - 1]) < get<1>(v[i - 1])) && (get<0>(v[j - 1]) > w && get<1>(v[j - 1]) > h))
            {
                // cout << i << " " << j << " : " << dp[j] << endl;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    vector<int> x;

    for(int i = n; i >= 1; i--)
    {
        if(dp[i - 1] < dp[i])
        {
            x.push_back(get<2>(v[i - 1]));
            // cout << i << endl;
        }
    }

    reverse(x.begin(), x.end());

    cout << x.size() << endl;
    for(auto u : x)
    {
        cout << u << " ";
    }

    // for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
}
