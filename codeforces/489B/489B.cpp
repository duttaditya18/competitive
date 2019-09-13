#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n], b[105] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m; cin >> m;
    int x;
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        b[x]++;
    }
    int c = 0;
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        if(b[a[i] - 1])
        {
            c++;
            b[a[i] - 1]--;
        }
        else if(b[a[i]])
        {
            c++;
            b[a[i]]--;
        }
        else if(b[a[i] + 1])
        {
            c++;
            b[a[i] + 1]--;
        }
    }
    cout << c << endl;
    return 0;
}
