#include <bits/stdc++.h>

using namespace std;
#define MAXL 5001
#define int long long

int a[MAXL];

signed main(void)
{
    int n, m; cin >> n >> m;

    int lx;

    // sum, max +ve from start, max +ve from end, max +ve
    vector<tuple<int, int, int, int>> v;
    v.push_back(make_tuple(0, 0, 0, 0));

    // sum, net +ve from start, net +ve from end, max so far, max element
    int sum, nps, npb, msf, ma;
    int cps, cpb, csf;
    for(int i = 1; i <= n; i++)
    {
        cin >> lx;
        nps = 0;
        cps = 0;
        msf = 0;
        csf = 0;
        ma = INT_MIN;
        sum = 0;
        for(int j = 1; j <= lx; j++)
        {
            cin >> a[j];
            sum += a[j];
            cps += a[j];
            csf += a[j];
            if(csf < 0) csf = 0;
            msf = max(csf, msf);
            nps = max(nps, cps);
            ma = max(ma, a[j]);
        }

        npb = 0;
        cpb = 0;
        for(int j = lx; j >= 1; j--)
        {
            cpb += a[j];
            npb = max(npb, cpb);
        }
        if(msf == 0) msf = ma;
        v.push_back(make_tuple(sum, nps, npb, msf));
    }

    // cout << endl; for(auto u : v) cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << " " << get<3>(u) << endl;

    // current sum, max so far
    int cur = 0, mas = 0, msx = INT_MIN;

    int b[m + 1] = {};

    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        mas = max({mas, cur + get<0>(v[b[i]]), cur + get<1>(v[b[i]])});
        cur = max(cur + get<0>(v[b[i]]), get<2>(v[b[i]]));
        msx = max(msx, get<3>(v[b[i]]));
    }
    if(mas == 0) mas = msx;
    cout << max(mas, msx) << endl;
}
