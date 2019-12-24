#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x, y, z; cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        v.push_back(make_pair(y + z, x));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = 0, cr = 0;

    for(int i = 0; i < n; i++)
    {
        cr += get<1>(v[i]);
        ans = max(ans, cr + get<0>(v[i]));
    }

    // for(int i = 0; i < n; i++) cout << get<0>(v[i]) << " " << get<1>(v[i]) << endl;

    cout << ans << endl;
}
