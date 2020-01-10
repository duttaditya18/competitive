#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;

        int a[n] = {};

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] -= i;
        }

        vector<int> v;
        v.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {
            if(a[i] >= v[v.size() - 1]) v.push_back(a[i]);
            else v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
        }

        cout << n - v.size() << endl;
    }
}
