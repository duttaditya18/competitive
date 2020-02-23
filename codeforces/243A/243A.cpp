#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> s;

    set<int> v1, v2;

    for(int i = 0; i < n; i++)
    {
        v2.insert(a[i]);
        for(auto u : v1) if(!(v2.count(u | a[i]))) v2.insert(u | a[i]);
        for(auto u : v2) if(!(s.count(u))) s.insert(u);
        v1 = v2;
        v2.clear();
    }
    cout << s.size() << "\n";
    return 0;
}
