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
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        bool ans = false;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i + 1] - a[i] == 1)
            {
                ans = true;
                break;
            }
        }
        cout << (ans ? 2 : 1) << "\n";
    }
    return 0;
}
