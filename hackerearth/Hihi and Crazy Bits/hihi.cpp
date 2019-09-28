#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, sz;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sz = log2(n) + 1;
        for(int i=0; i<=sz; i++)
        {
            if(!(n & (1<<i)))
            {
                cout << (n | (1<<i)) << endl;
                break;
            }
        }
    }
}
