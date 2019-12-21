#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first != p2.first) return (p1.first < p2.first);
    return (p1.second < p2.second);
}

int main(void)
{
    int n; cin >> n;
    vector<pair<int, int>> v;

    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), comp);

    // for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << endl;

    int l = v[0].first, r = v[0].second, c = 1;

    for(int i = 1; i < n; i++)
    {
        // cout << l << " " << r << " " << v[i].first << " " << v[i].second << endl;
        if(v[i].first <= r) r = min(r, v[i].second);
        else
        {
            c++;
            r = v[i].second;
        }
        l = v[i].first;
    }

    cout << c << endl;
}
