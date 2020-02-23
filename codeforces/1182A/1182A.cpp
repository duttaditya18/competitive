#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    if(n % 2) cout << 0;
    else cout << (1LL << (n / 2));
    cout << "\n";
}
