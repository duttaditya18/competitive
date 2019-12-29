#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        long long a, m; cin >> a >> m;

        vector<long long> v;
        vector<long long> vx;

        for(int i = 1; i*i <= m; i++)
        {
            if(!(m % i))
            {
                // cout << i << " " << m / i << endl;
                long long x = ((m / i) - 1) / a;
                if((((x * a) + 1) * i) == m) v.push_back(x * i);
                if((m / i) != i)
                {
                    long long y = (i - 1) / a;
                    // cout << y << endl;
                    if(((y * a) + 1) == i) vx.push_back((y * m) / i);
                }
            }
        }
        cout << v.size() - 1 + vx.size() << endl;
        for(auto u : vx)
        {
            if(u!= 0) cout << u << " ";
        }
        for(int i = v.size() - 1; i >= 0; i--)
        {
            if(v[i] != 0) cout << v[i] << " ";
        }
        cout << endl;
    }
}
