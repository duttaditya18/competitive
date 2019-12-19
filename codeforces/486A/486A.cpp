#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long a;
    cin >> a;

    if(a % 2) cout << (a - 1)/2 - a;
    else cout << a/2;

    cout << endl;
    return 0;
}
