#include <bits/stdc++.h>

using namespace std;

int countValues (int n)
{
    int c = 0;
    while(n)
    {
        if(!(n & 1)) c++;
        n >>= 1;
    }
    return (1 << c);
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n; cin >> n;

        cout << countValues(n) << "\n";
    }
    return 0;
}
