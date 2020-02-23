#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#

int main(void)
{
    int n; cin >> n;

    vector<pair> adj[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        adj[x].pb(y);
    }
}
