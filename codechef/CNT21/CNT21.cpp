#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n; cin >> n;
        char c; cin >> c;
        int x; cin >> x;

        int a; for(int i = 0; i < x; i++) cin >> a;

        n -= x;
        n %= 4;

        if(n == 1) cout << c;
        else cout << (c == 'A' ? 'B' : 'A');
        cout << endl;
    }
    return 0;
}
