#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    long long n;

    while(t--)
    {
        cin >> n;
        long long x = (n - 1) % 4;
        string s = to_string((n - 1) / 4);
        if(s == "0") s = "";
        if(x == 0)
        {
            s += "192";
        }
        else if(x == 1)
        {
            s += "442";
        }
        else if(x == 2)
        {
            s += "692";
        }
        else if(x == 3)
        {
            s += "942";
        }
        cout << s << endl;
        // cout << 192 + (250 * (n - 1)) << endl;
    }
    return 0;
}
