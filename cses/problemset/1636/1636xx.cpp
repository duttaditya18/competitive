#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), d(x + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    d[0] = 1;
    for (int c : a)
    for (int i = 1; i <= x; i++)
      if (c <= i) d[i] = (d[i] + d[i - c]) % 1000000007;
    cout << d[x] << "\n";


    for(int i = 0; i < x + 1; i++)
    {
        cout << i << " : " << d[i]<< endl;
    }
    return 0;
}
