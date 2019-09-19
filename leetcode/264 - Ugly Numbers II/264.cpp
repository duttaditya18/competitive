#include <bits/stdc++.h>

using namespace std;

int nthUglyNumber(int n)
{
    vector<int> primes{2,3,5};
    int x = primes.size();

    vector<long long> u;
    u.push_back(1);

    long long counter[x], curr[x];
    for(int i = 0; i < x; i++)
    {
        counter[i] = 0;
        curr[i] = u[counter[i]]*primes[i];
    }

    int  mihrcr , counts = 1;

    while(counts < n)
    {
        mihrcr = 0;
        for(int i = 0; i < x; i++)
        {
            if(curr[i] < curr[mihrcr])
            {
                mihrcr = i;
            }
        }
        u.push_back(curr[mihrcr]);
        for(int i = 0; i < x; i++)
        {
            if(u[counts] == curr[i])
            {
                counter[i]++;
                curr[i] = u[counter[i]] * primes[i];
            }
        }
        counts++;
    }

    return u[n - 1];
}

vector<int> primes{2,7,13,19};
int main(void)
{
    int n = 10;
    cout << nthUglyNumber(n);
    return 0;
}
