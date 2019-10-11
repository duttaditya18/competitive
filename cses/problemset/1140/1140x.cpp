
// TLE

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    // end, start, reward
    vector<tuple<int, int, int>> jobs;

    int s, e, r, en[n];

    for(int i = 0; i < n; i++)
    {
        cin >> s >> e >> r;
        en[i] = e;
        jobs.push_back({e, s, r});
    }

    sort(jobs.begin(), jobs.end());
    sort(en, en + n);

    cout << endl;
    for(int i = 0; i < n; i++) cout << get<1>(jobs[i]) << " " << get<0>(jobs[i]) << " " << get<2>(jobs[i]) << endl;
    cout << endl;
    //for(int i = 0; i < n; i++) cout << en[i] << endl;

    int sp, ep, rp;

    long long dp[n], maxtn = 0;

    dp[0] = get<2>(jobs[0]);

    for(int i = 1; i < n; i++)
    {
        tie(e, s, r) = jobs[i];

        int left = 0, right = i - 1, m;
        while(right - left  > 1)
        {
            m = (right + left) / 2;
            if(en[m] >= s) right = m;
            if(en[m] < s) left = m;
        }

        if(en[m] == s) m--;
        cout << m<< endl;

        dp[i] = max(dp[i - 1], 1ll*r);

        if(en[m] < s) dp[i] = max(dp[i], dp[m] + r);
    }


    cout << endl;
    for(int i = 0; i < n; i++) cout << dp[i] << endl;

    cout << endl;
    cout << dp[n - 1] << endl;
    return 0;
}
