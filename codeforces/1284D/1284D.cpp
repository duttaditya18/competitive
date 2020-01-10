#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int, int> p1, tuple<int, int, int> p2)
{
    if(get<0>(p1) != get<0>(p2)) return (get<0>(p1) < get<0>(p2));
    else return (get<2>(p1) != get<2>(p2));
}

int main(void)
{
    int n; cin >> n;

    int sa, ea, sb, eb;

    // position, event number, start = 0 & end = 1;
    vector<tuple<int, int, int>> va;
    vector<tuple<int, int, int>> vb;
    for(int i = 1; i <= n; i++)
    {
        cin >> sa >> ea >> sb >> eb;
        va.push_back(make_tuple(sa, i, 0));
        va.push_back(make_tuple(ea, i, 1));
        vb.push_back(make_tuple(sb, i, 0));
        vb.push_back(make_tuple(eb, i, 1));
    }

    sort(va.begin(), va.end(), comp);
    sort(vb.begin(), vb.end(), comp);

    // for(auto u : va) cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << endl;

    int cur = get<1>(v[0]);

    for(int i = 1; i < (2 * n); i++)
    {
        if(cur != get<1>(v[i]))
    }
}
