#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n + 1] = {};
    int st[n + 1] = {};
    int en[n + 1] = {};

    for(int i = 1; i <= n; i++) cin >> a[i];

    st[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i - 1]) st[i] = st[i - 1] + 1;
        else st[i] = 1;
    }

    en[n] = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] < a[i + 1]) en[i] = en[i + 1] + 1;
        else en[i] = 1;
    }

    int mas = 0;

    a[0] = INT_MIN;

    for(int i = 1; i < n; i++)
    {
        mas = max({mas, st[i], en[i]});
        if(a[i - 1] < a[i + 1]) mas = max(mas, st[i - 1] + en[i + 1]);
    }

    cout << mas << "\n";
    return 0;
}
