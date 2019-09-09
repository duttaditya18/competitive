#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    map <long long, long long> c;
    map <long long, long long> ans;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    int ma = *max_element(a, a + n);
    int mi = *min_element(a, a + n);
    /*cout << endl;
    for(map<int, int>::iterator it = c.begin(); it != c.end(); it++)
    {
        cout<< it->first << " "<< it->second << endl;
    }*/
    ans[0] = 0;
    ans[mi] = c[mi]*mi;

    for(int i = mi + 1; i <= ma; i++)
    {
        ans[i] = max(ans[i - 1], ans[i - 2] + (c[i]*i));
    }

    cout << ans[ma];

    return 0;
}
