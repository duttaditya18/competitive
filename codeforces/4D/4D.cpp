#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int, int> p1, tuple<int, int, int> p2)
{
    if(get<0>(p1) == get<0>(p2)) return get<1>(p1) < get<1>(p2);
    return get<0>(p1) < get<0>(p2);
}

bool itFits(int w1, int h1, int w2, int h2)
{
    if(w1 < w2 && h1 < h2) return true;
    return false;
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


    int dp[n + 1] = {}, prev[n + 1] = {}, maxEver = 0;

    for(int i = 1; i <= n; i++)
    {
        if(itFits(w, h, get<0>(v[i - 1]), get<1>(v[i - 1])))
        {
            dp[i] = 1;
            int ma = 0;
            for(int j = 1; j < i; j++)
            {
                if(itFits(get<0>(v[j - 1]), get<1>(v[j - 1]), get<0>(v[i - 1]), get<1>(v[i - 1])))
                {
                    if(dp[j] > ma)
                    {
                        ma = dp[j];
                        prev[i] = j;
                    }
                }
            }
            dp[i] = ma + 1;
        }
        if(dp[i] > dp[maxEver])
        {
            maxEver = i;
        }
    }

    //cout << endl; for(int i = 0; i < n; i++) cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << endl;
    //for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
    //for(int i = 0; i <= n; i++) cout << prev[i] << " "; cout << endl;

    cout << dp[maxEver] << endl;

    if(dp[maxEver] == 0) return 0;

    int cur = prev[maxEver];

    vector<int> ans;
    ans.push_back(get<2>(v[maxEver - 1]));

    while(cur != 0)
    {
        ans.push_back(get<2>(v[cur - 1]));
        cur = prev[cur];
    }

    reverse(ans.begin(), ans.end());
    for(auto u : ans) cout << u << " "; cout << endl;

    return 0;
}
