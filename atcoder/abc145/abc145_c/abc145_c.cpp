#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int x[n] = {}, y[n] = {};
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        v.push_back(i);
        cin >> x[i] >> y[i];
    }


    double ans = 0.0, cnt = 0.0;

    do
    {
        for(int i = 1; i < n; i++)
        {
            //cout << sqrt(1.0*x[v[i]]*x[v[i]] + 1.0*y[v[i]]*y[v[i]]);
            ans += sqrt((x[v[i - 1]] - x[v[i]])*(x[v[i - 1]] - x[v[i]]) + (y[v[i - 1]] - y[v[i]])*(y[v[i - 1]] - y[v[i]]));
        }
        cnt++;
    }
    while (next_permutation(v.begin(), v.end()));
    ans /= cnt;
    cout << ans << endl;
}
