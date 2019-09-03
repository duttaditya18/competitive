#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        ull n, m;
        cin >> n >> m;
        ull x = n / m;

        int v[10];

        for(int i = 0; i < 10; i++)
        {
            v[i] =  (i * m) % 10;
        }

        ull ans = 0;

        for(int i = 0; i < 10; i++)
        {
            ans += v[i] * (x / 10);
            if(i <= (x % 10))
            {
                ans += v[i];
            }
        }
        cout << ans << endl;
    }
}
