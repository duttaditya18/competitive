#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int a, b;

    int deg[n + 1] = {};

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    int mi = INT_MAX, ma = INT_MIN;

    int oc0 = 0, oc1 = 0, oc2 = 0, ocE = 0;

    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0) oc0++;
        if(deg[i] == 1) oc1++;
        else if(deg[i] == 2) oc2++;
        else ocE++;
    }


    if(oc0 > 0)
    {
        cout << "unknown topology";
    }
    else if(oc1 == 0 && oc2 > 1 && ocE == 0)
    {
        cout << "ring topology";
    }
    else if(oc1 == 2 && oc2 >= 1 && ocE == 0)
    {
        cout << "bus topology";
    }
    else if(oc1 > 1 && oc2 == 0 && ocE == 1)
    {
        cout << "star topology";
    }
    else
    {
        cout << "unknown topology";
    }
    cout << "\n";
    return 0;
}
