#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    int o = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]) o++;
    }
    int ma = 0, ms = 0;
    for(int i = 0; i < n; i++)
    {
        if(!a[i]) ma++;
        else if(a[i]) ma--;
        if(ma < 0) ma = 0;
        ms = max(ms, ma);
    }
    if(ms) cout << o + ms << endl;
    else if(!ms) cout << (o - 1) << endl;
    return 0;
}
