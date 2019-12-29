#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    int a, b;
    while(t--)
    {
        cin >> a >> b;
        if(a < b) swap(a, b);
        int d = a - b;
        if(d == 0) { cout << 0 << "\n"; return 0; }
        long long n  = 0;
        long long i = 1;
        for(; n <= d; i++)
        {
            n += i;
        }
        n -= i;
        cout << n << endl;
    }
}
