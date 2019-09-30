// TLE

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    // end, start, reward
    vector<tuple<int, int, int>> jobs;

    int s, e, r;

    for(int i = 0; i < n; i++)
    {
        cin >> s >> e >> r;
        jobs.push_back({e, s, r});
    }

    sort(jobs.begin(), jobs.end());

    //for(int i = 0; i < n; i++) cout << get<0>(jobs[i]) << " " << get<1>(jobs[i]) << " " << get<2>(jobs[i]) << endl;

    int sp, ep, rp;

    long long dp[n], maxtn = 0;

    for(int i = 0; i < n; i++)
    {
        tie(e, s, r) = jobs[i];
        long long ma = r;
        for(int j = 0; j < i; j++)
        {
            tie(ep, sp, rp) = jobs[j];
            if(ep < s) ma = max(ma, dp[j] + r);
        }
        dp[i] = ma;
        maxtn = max(maxtn, dp[i]);
    }
    cout << maxtn << endl;
    return 0;
}
