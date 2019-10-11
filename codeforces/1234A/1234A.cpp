#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        int x = n;
        int sum = 0;
        int a;
        while(x--)
        {
            cin >> a;
            sum += a;
        }
        int ans = sum / n;
        if(sum % n) ans++;
        cout << ans << endl;
    }
    return 0;
}
