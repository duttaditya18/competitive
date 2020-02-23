#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n, x, k, s = 0; cin >> n >> k;
    while(n--) cin >> x, s += (!(x % k));
    cout << s << "\n";
}
