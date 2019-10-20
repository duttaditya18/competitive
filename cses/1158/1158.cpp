#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    // cost, pages
    int c[n], p[n];

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    // maximum value that you can get with i amount of cash = a[i]
    int a[x + 1] = {};

    for(int i = 0; i < n; i++)
    {
        // start checking from backside to not have duplication
        for(int j = x; j >= 1; j--)
        {
            if(j >= c[i])
            {
                a[j] = max(a[j], a[j - c[i]] + p[i]);
            }
            //cout << i << " : " << j << " : " << c[i] << " : "  << p[i] << " : " << a[j] << endl;
        }
        //cout << endl;
    }
    cout << a[x] << endl;
    return 0;
}
