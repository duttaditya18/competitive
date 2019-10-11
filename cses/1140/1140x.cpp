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
        jobs.push_back(make_tuple(e, s, r));
    }

    sort(jobs.begin(), jobs.end());


    //cout << endl; for(int i = 0; i < n; i++) cout << get<1>(jobs[i]) << " " << get<0>(jobs[i]) << " " << get<2>(jobs[i]) << endl; cout << endl;

    long long dp[n] = {};

    dp[0] = get<2>(jobs[0]);

    for(int i = 1; i < n; i++)
    {
        tie(e, s, r) = jobs[i];

        // lower_bound() compares the first value in a tuple
        int k = lower_bound(jobs.begin(), jobs.end(), make_tuple(s, 0, 0)) - jobs.begin() - 1;

        long long incl = (long long) r;
        if(k >= 0) incl += dp[k];

        dp[i] = max(dp[i - 1], incl);
    }

    //cout << endl; for(int i = 0; i < n; i++) cout << dp[i] << endl;

    cout << dp[n - 1] << endl;
    return 0;
}
