#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000010

unsigned long long a[MAXN];

int main()
{
    unsigned long long n, m, cnt = 1, q;
    queue<long long> q1, q2;
    unsigned long long ans;

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<long long>());

    for(auto u : a) q1.push(u);

    while(m--)
    {
        cin >> q;
        while(cnt <= q)
        {
            // cout << "c" << cnt << endl;
            if(q1.front() >= q2.front() || q2.empty())
            {
                ans = q1.front();
                q1.pop();
            }
            else
            {
                ans = q2.front();
                q2.pop();
            }
            q2.push(ans / 2) ;
            cnt++;
        }
        cout << ans << endl;
    }

    return 0;
}
