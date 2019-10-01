// WA Mate

#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<long long, long long, long long> &a, tuple<long long, long long, long long> &b)
{
    if(get<0>(a) != get<0>(b)) return (get<0>(a) < get<0>(b));
    else return (get<1>(a) < get<1>(b));
}

int main(void)
{
    ifstream cin("output.txt");
    ofstream cout("ok.txt");
    long long n, m, w, b;
    cin >> n >> m >> w >> b;

    // x, y, 0 - W, 1 - B
    vector<tuple<long long, long long, long long>> v;

    long long x, y;
    for(long long i = 0; i < w; i++)
    {
        cin >> x >> y;
        v.push_back({x, y, 0});
    }
    for(long long i = 0; i < b; i++)
    {
        cin >> x >> y;
        v.push_back({x, y, 1});
    }

    sort(v.begin(), v.end(), comp);

    unsigned long long ans = 1ll*n*m*(m+1)/2;

    bool firstW = false;
    long long isB, curx = 0;
    long long destroyed;
    for(long long i = 0; i < w + b; i++)
    {
        tie(x, y, isB) = v[i];
        cout << x << " " << y << " " << isB << endl;
        if(curx != x)
        {
            firstW = false;
            destroyed = 0;
            curx = x;
        }

        if(isB)
        {
            ans = ans - (y - 1 - destroyed - firstW) * (m - y) * 1ll;
            ans = ans - (m - y + 1) * 1ll;
            firstW = false;
            destroyed = y;
        }
        else if(!isB)
        {
            if(firstW)
            {
                ans = ans - (y - 1 - destroyed - firstW) * (m - y) * 1ll;
                ans = ans - (m - y + 1) * 1ll;
                firstW = false;
                destroyed = y;
            }
            else if(!firstW)
            {
                ans = ans - (m - y + 1) *  1ll;
                firstW = true;
            }
        }
    }

    cout << ans << endl;
    //for (long long i = 0; i < v.size(); i++) cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
}
