#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n, x; cin >> n;
        int an = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            an = max(an, x);
        }
        cout << an << "\n";
    }
    return 0;
}
