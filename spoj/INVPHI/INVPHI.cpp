#include <bits/stdc++.h>

using namespace std;

// 160180000
const long long maxn = 160180000;

long long phi[maxn + 10];
vector<bool>mark(maxn,0);
int m[maxn];
long long n;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    for(int i = 2; i <= maxn; i++) phi[i] = i - 1;
    for(int i = 2; i <= maxn; i++)
    {
        for(int j = i + i; j <= maxn; j += i) phi[j] -= phi[i];
        if(!mark[phi[i]])
        {
            m[phi[i]] = i;
            mark[phi[i]] = 1;
        }
    }

    int t; cin >> t;

    while(t--)
    {
        cin >> n;
        if(mark[n])
            cout << m[n];
        else
            cout << -1;
        cout << "\n";
    }
    return 0;
}
