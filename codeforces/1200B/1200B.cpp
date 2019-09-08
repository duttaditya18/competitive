#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int h[n];
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int diff, diffx;
        bool flag = true;
        for(int i = 0; i < n - 1; i++)
        {
            diff = h[i + 1] - h[i];
            diffx = diff - k;
            if(diffx > 0)
            {
                if(m >= diffx)
                {
                    m -= diffx;
                }
                else
                {
                    flag = false;
                    break;
                }

            }
            else if(diffx < 0)
            {
                if(-diffx > h[i])
                {
                    m += h[i];
                }
                else
                {
                    m += -diffx;
                }

            }
            else if(diffx == 0)
            {
                continue;
            }
        }
        cout << ((flag == true) ? "YES\n" : "NO\n");
    }
    return  0;
}
