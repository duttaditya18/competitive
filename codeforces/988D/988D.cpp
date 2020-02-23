#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e9;

int main(void)
{
    int n; cin >> n;
    int a[n];
    set<int> s;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    vector<int> ans;
    bool f = true;

    for(int i = 0; (i < n) && f; i++)
    {
        // cout << a[i] << endl;
        for(int j = 0; j <= 30; j++)
        {
            if(a[i] - (1 << j) >= -maxn)
            {
                if((s.count(a[i] - (1 << j))) && (ans.size() < 2))
                {
                    ans.push_back(a[i]);
                    ans.push_back(a[i] - (1 << j));
                }
            }
            if(a[i] + (1 << j) <= maxn)
            {
                if((s.count(a[i] + (1 << j))) && (ans.size() < 2))
                {
                    ans.push_back(a[i]);
                    ans.push_back(a[i] + (1 << j));
                }
            }
            if((a[i] + (1 << j) <= maxn) && (a[i] - (1 << j) >= -maxn))
            {
                if((s.count(a[i] - (1 << j))) && (s.count(a[i] + (1 << j))))
                {
                    ans.clear();
                    ans.push_back(a[i] - (1 << j));
                    ans.push_back(a[i]);
                    ans.push_back(a[i] + (1 << j));
                    f = false;
                    break;
                }
            }
        }
    }

    if(ans.size() == 0)
    {
        cout << 1 << "\n";
        cout << a[0];
    }
    else
    {
        cout << ans.size() << "\n";
        for(auto u : ans) cout << u << " ";
    }
    cout << "\n";
}
