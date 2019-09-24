#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int q, sum, x;
    cin >> q;
    while(q--)
    {
        sum = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(x <= 2048) sum += x;
        }
        cout << ((sum >= 2048) ? "YES\n" : "NO\n");
    }
    return 0;
}
