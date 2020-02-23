#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int s, x; cin >> s >> x;

    int c = s;
    vector<int> v;

    for(int i = x; i >= 1; i--)
    {
        if(c >= (i & -i))
        {
            c -= (i & -i);
            v.push_back(i);
        }
    }

    if(c != 0) cout << -1;
    else
    {
        cout << v.size() << "\n";
        for(auto u : v) cout << u << " ";
    }
    cout << "\n";
    return 0;
}
