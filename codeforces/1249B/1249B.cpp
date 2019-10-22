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

        for(int i = 0; i < n; i++)
        {
            int curr = a[i];
            int cnt = 1;
            while(curr != i + 1)
            {
                curr = a[curr - 1];
                cnt++;
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}
