#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first * a.second < b.first*b.second;
}
int main()
{
    int n; cin>>n;
    pair<int,int> a[n];
    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    sort(a,a+n,cmp);

    double ans = a[0].first * 1.0 * a[0].second / 2.0;

    cout << endl;
    for (int i = 1; i<n; i++)
    {
        ans = max(ans, 1.0 * a[i].first * a[i].second / 2);
        ans = max(ans, min(a[i-1].first, a[i].first) * 1.0 * min(a[i-1].second,a[i].second));
        ans = max(ans, min(a[i-1].first, a[i].second) * 1.0 * min(a[i-1].second,a[i].first));
        ans = max(ans, 1.0 * min(a[i-1].second, a[i].first) * 1.0 * min(a[i-1].first,a[i].second));
    }
    cout<<ans<<endl;
}
