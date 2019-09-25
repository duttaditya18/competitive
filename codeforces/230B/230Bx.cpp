#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> sieve(1000006, 0);
    long long t, sqr;
    int n;
    cin >> n;

    int cur;

    sieve[1] = 1;
    for(int i = 2; i < 1000; i++)
        if(!sieve[i])
            for(cur = 2*i; cur < 1000006; cur += i)
                sieve[cur] = 1;

    while(n--)
    {
        cin >> t;
        sqr = sqrtl(t);
        if(sqr*sqr == t && !sieve[sqr])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
