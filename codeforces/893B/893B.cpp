#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x, f; cin >> n;
    for(int i = 1; x <= n; i++)
    {
        x = (((1 << i) - 1) << (i - 1));
        if(!(n % x)) f = x;
    }
    cout << f << "\n";
}
