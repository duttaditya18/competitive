#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int maxd = 30;
int n, s;
int x, y;

string xo(pair<double, double> pos, pair<double, double> s1, pair<double, double> s2, pair<double, double> s3, pair<double, double> s4, string str, int d)
{
    if(d == maxd) return str;

    if(pos.fi <= (s3.fi / 2) && pos.se <= (s3.se / 2))
        return ("1" + xo(make_pair(1.0 * x, 1.0 * y), make_pair(s1.fi, s2.se), make_pair(0.0, s * 1.0), make_pair(s * 1.0, s * 1.0), make_pair(s * 1.0, 0.0), "", 0));

    if(pos.fi <= (s3.fi / 2) && pos.se <= s2.se)
        return

    if(pos.fi <= s4.fi && pos.se <= (s3.se / 2)
       return

    return
}


int main(void)
{
    cin >> n >> s;
    pair<string, string> p[n];

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> p[i].se;
        p[i].fi = xo(make_pair(1.0 * x, 1.0 * y), make_pair(0.0, 0.0), make_pair(0.0, s * 1.0), make_pair(s * 1.0, s * 1.0), make_pair(s * 1.0, 0.0), "", 0);
    }

    sort(p, p + n);

    for(auto u: p)
    {
        cout << u.fi << " " << u.se << "\n";
    }
}
