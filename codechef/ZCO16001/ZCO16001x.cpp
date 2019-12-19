#include <bits/stdc++.h>

using namespace std;

int n, k;

int getAns(vector<int> f, vector<int> u)
{
    int ck = k;

    int l = 0, r = n - 1;

    while(ck > 0)
    {
        if(f[l] >= u[r]) break;
        if(l >= n || r < 0) break;

        swap(f[l], u[r]);
        l++;
        r--;
        ck--;
    }
    sort(f.begin(), f.end());
    sort(u.begin(), u.end());

    return (f[n - 1] + u[n - 1]);
}

int main(void)
{
    cin >> n >> k;

    vector<int> a, b;
    int x;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;

    ans = min(getAns(a, b), getAns(b, a));

    cout << ans << endl;
    return 0;
}
