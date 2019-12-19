#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first != p2.first) return p1.first < p2.first;

    return p1.second < p2.second;
}

int main(void)
{
    int n; cin >> n;

    int x, y;

    vector<pair<int, int>> a = {};

    long long large = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back(make_pair(min(x, y), max(x, y)));
        large = max(large, 1ll * x * y);
    }

    sort(a.begin(), a.end(), comp);

    // cout << endl; for(int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << endl;

    long long ans = 0;

    for(int i = 1; i < n; i++)
    {
        //ans = max(ans, 1.0 * a[i].first * a[i].second / 2);
        ans = max( ans, max( ( 1ll* min(a[i].first, a[i - 1].first) * min(a[i].second, a[i - 1].second) ),
                            ( 1ll * min(a[i].second, a[i - 1].first) * min(a[i].first, a[i - 1].second) ) ) );

        //cout << ans << endl;
    }

    if(large / 2 >= ans)
    {
        if(large % 2) cout << large / 2 << ".5";
        else cout << large << ".0";
        return 0;
    }

    cout << ans <<  ".0" << endl;
}

/*
14
1 1
1 2
1 3
3 4
1 13
1 14
1 15
1 16
1 17
1 18
1 19
1 20
4 5
1 21

3
1 9
1 1
1 2
*/
