#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n + 2] = {};

        for(int i = 1; i <= n; i++) cin >> a[i];

        // 1 - smaller than previous, 0 - larger than previous
        int cur = 1;
        int endat[n + 1] = {};

        endat[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(cur)
            {
                if(a[i] >= a[i - 1])
                {
                    endat[i] = endat[i - 1] + 1;
                    cur = !cur;
                }
                else endat[i] = 1;
            }
            else if(!cur)
            {
                if(a[i] <= a[i - 1])
                {
                    endat[i] = endat[i - 1] + 1;
                    cur = !cur;
                }
                else endat[i] = 2;
            }
        }

        // 0 - smaller than next, 1 - larger than next
        int startat[n + 1][2] = {};

        startat[n][0] = 1;
        startat[n][1] = 1;
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] < a[i + 1])
            {
                startat[i][0] = startat[i + 1][1] + 1;
                startat[i][1] = 1;
            }

            if(a[i] > a[i + 1])
            {
                startat[i][1] = startat[i + 1][0] + 1;
                startat[i][0] = 1;
            }

            if(a[i] == a[i + 1])
            {
                startat[i][0] = startat[i + 1][1] + 1;
                startat[i][1] = startat[i + 1][0] + 1;
            }
        }


        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, endat[i] + startat[i][0]);
        }

        cout << ans << endl;

        // for(int i = 1; i <= n; i++) cout << endat[i] << " "; cout << endl;
        // for(int i = 1; i <= n; i++) cout << startat[i][0] << " "; cout << endl;
        // for(int i = 1; i <= n; i++) cout << startat[i][1] << " "; cout << endl;
    }
}
