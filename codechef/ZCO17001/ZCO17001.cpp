#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream cin("gen.txt");
    int n; cin >> n;
    int t; cin >> t;

    int s[n + 1] = {};

    // 0 - using 1, 1 - using 2, 2 - using 3, 3 - using 4
    unordered_map<long long, long long> mp[4];
    unordered_map<long long, long long> np[4];

    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    //for(auto u : mp[0]) cout << u.first << " " << u.second << endl;

    for(int i = 1; i <= n; i++)
    {
        np[0][1ll*s[i]]++;
        for(auto u : mp[0]) np[1][1ll*u.first + s[i]] += u.second;
        for(auto u : mp[1]) np[2][1ll*u.first + s[i]] += u.second;
        for(auto u : mp[2]) np[3][1ll*u.first + s[i]] += u.second;

        for(auto u : mp[0]) np[0][1ll*u.first] += u.second;
        for(auto u : mp[1]) np[1][1ll*u.first] += u.second;
        for(auto u : mp[2]) np[2][1ll*u.first] += u.second;
        for(auto u : mp[3]) np[3][1ll*u.first] += u.second;

        mp[0] = np[0];
        mp[1] = np[1];
        mp[2] = np[2];
        mp[3] = np[3];
        np[0].clear();
        np[1].clear();
        np[2].clear();
        np[3].clear();
    }

    /*cout << endl;
    for(auto u : mp[0]) cout << u.first << " " << u.second << endl; cout << endl;
    for(auto u : mp[1]) cout << u.first << " " << u.second << endl; cout << endl;
    for(auto u : mp[2]) cout << u.first << " " << u.second << endl; cout << endl;
    for(auto u : mp[3]) cout << u.first << " " << u.second << endl; cout << endl;*/
    cout << mp[3][t] << endl;
}
