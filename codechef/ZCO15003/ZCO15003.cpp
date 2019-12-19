#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first <= p2.first);
}

int main(void)
{
    int n; cin >> n;

    // 0 - Start, 1 - End
    vector<pair<int, int>> v;

    int x, y;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, 0));
        v.push_back(make_pair(y, 1));
    }

    sort(v.begin(), v.end(), comp);

    bool b = true;
    int ans = 0;

    //for(int i = 0; i < (2*n); i++) cout << v[i].first << " " << v[i].second << endl;

    for(int i = 0; i < (2*n); i++)
    {
        if(b)
        {
            if(v[i].second == 0) b = !b;
            else continue;
        }
        else if(!b)
        {
            if(v[i].second == 1)
            {
                ans++;
                b = !b;
            }
            else continue;
        }
    }

    cout << ans << endl;
}
