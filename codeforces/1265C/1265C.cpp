#include <bits/stdc++.h>

using namespace std;
#define MAXN 400010

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        vector<int> a;

        int x, n; cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        reverse(a.begin(), a.end());
        int f = n / 2;
        if(n  % 2) f++;
        // cout << f << endl;
        int ub = (upper_bound(a.begin(), a.end(), a[f - 1]) - a.begin());
        // cout << ub << endl;
        int c = 0, g = 1, s = 1, b = 1;

        for(int i = n - 2; i >= (ub); i--)
        {
            if(c == 0)
            {
                if(a[i] != a[i + 1]) c = 1;
                else g++;
            }
            else if(c == 1)
            {
                if(a[i] != a[i + 1] && (g < s)) c = 2;
                else s++;
            }
            else b++;
        }
        if(g >= s || g >= b)
        {
            cout << 0 << " " << 0 << " " << 0 << endl;
            continue;
        }
        cout << g << " " << s << " " << b << endl;
    }
}
