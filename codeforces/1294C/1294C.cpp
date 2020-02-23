#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        int x = -1, y = -1;
        for(int i = 2; i*i <= n; i++)
        {
            if(!(n % i))
            {
                x = i;
                break;
            }
        }
        for(int i = 2; i*i <= n/x; i++)
        {
            if(!((n/x) % i) && i != x)
            {
                y = i;
                break;
            }
        }
        if(x == -1 || y == -1 || n/(x*y) == x || n/(x*y) == y) cout << "NO";
        else cout << "YES\n" << x << " " << y << " " << n/(x*y);
        cout << "\n";
    }
    return 0;
}
