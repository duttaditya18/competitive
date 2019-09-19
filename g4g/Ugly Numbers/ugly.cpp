#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    vector<int> n;

    int te, ma = 0;
    for(int i = 0; i < t; i++)
    {
        cin >> te;
        n.push_back(te);
        ma = max(te, ma);
    }

    vector<long long> u;
    u.push_back(1);

    long long counter[3], curr[3], nos[3] = {2, 3, 5};
    for(int i = 0; i < 3; i++)
    {
        counter[i] = 0;
        curr[i] = u[counter[i]]*nos[i];
    }

    int  mihrcr , counts = 1;

    while(counts < ma)
    {
        mihrcr = 0;
        for(int i = 0; i < 3; i++)
        {
            if(curr[i] < curr[mihrcr])
            {
                mihrcr = i;
            }
        }
        u.push_back(curr[mihrcr]);
        for(int i = 0; i < 3; i++)
        {
            if(u[counts] == curr[i])
            {
                counter[i]++;
                curr[i] = u[counter[i]] * nos[i];
            }
        }
        counts++;
    }

    /*for(int i = 0; i < u.size(); i++)
        cout << u[i] << endl;*/

    for(int i = 0; i < t; i++)
    {
        cout << u[n[i] - 1] << endl;
    }

    return 0;
}
