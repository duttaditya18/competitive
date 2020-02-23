#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n = 1, ans = 0;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        ans = n;
        for(int i = 2; i * i <= n; i++)
        {
            if(!(n % i))
            {
                while(!(n % i)) n /= i;
                ans -= (ans / i);
            }
        }

        if(n > 1) ans -= (ans / n);
        cout << ans << "\n";
    }
    return 0;
}
