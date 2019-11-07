#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n;
    cin >> n;

    long long c = 0, p = 0;

    for(long long i = 2 ; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            p = i;
            c++;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1) c += 1;

    if(c <= 1)
    {
        cout << max(n, p) << endl;
        return 0;
    }

    if(c > 1)
    {
        cout << 1 << endl;
        return 0;
    }

}
