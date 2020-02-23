#include <bits/stdc++.h>

using namespace std;
const long long maxn = 2*1e9;

int main(void)
{
    long long cur = 2, ba = INT_MIN;
    while(1)
    {
        long long g = cur;
        long long h = g;
        for(int i = 2; i*i <= cur; i++)
        {
            if(!(g % i))
            {
                while(!(g % i)) g /= i;
                h -= h/i;
            }
        }
        if(g > 1) h -= h/g;
        if(h - ba >= 1000000)
        {
            cout << cur << " " << h << "\n";
            ba = h;
        }
        cur++;
    }
}
