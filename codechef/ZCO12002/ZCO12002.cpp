#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x, y; cin >> n >> x >> y;

    vector<int> s, e, v, w;
    int a, b;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.push_back(a);
        e.push_back(b);
    }
    for(int i = 0; i < x; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < y; i++)
    {
        cin >> a;
        w.push_back(a);
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    //cout << endl;
    //for(int i = 0; i < n; i++) { cout << s[i] << " " << e[i] << endl; } cout << endl;
    //for(int i = 0; i < x; i++) cout << v[i] << " "; cout << endl;
    //for(int i = 0; i < y; i++) cout << w[i] << " "; cout << endl;

    int mi = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(v[0] > s[i]) continue;
        if(w[y - 1] < e[i]) continue;
        int l = *(upper_bound(v.begin(), v.end(), s[i]) - 1);
        int r = *(lower_bound(w.begin(), w.end(), e[i]));

        //cout << r << " " << l << endl;

        mi = min(mi, r - l + 1);
    }
    cout << mi << endl;
}
