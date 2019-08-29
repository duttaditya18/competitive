#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream cin("learning.in");
    ofstream cout("learning.out");

    int n, a, b, t1, t2;
    string ts;
    cin >> n >> a >> b;
    vector <pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        cin >> ts >> t1;
        if(ts == "NS") t2 = 0;
        else if(ts == "S") t2 = 1;

        v.push_back(make_pair(t1, t2));
    }

    sort(v.begin(), v.end());

    /*cout << a << " " << b << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }*/
    //cout << endl;

    int curi = 0, ans = 0, curdif;

    for(int i = a; i <= b; i++)
    {
        curdif = INFINITY;
        for(int j = curi; abs(v[j].first - i) < curdif; j++)
        {
            curdif = abs(v[j].first - i);
            curi = j;
        }
        if(curdif == abs(v[curi + 1].first - i) and v[curi + 1].second == 1)
        {
            curi++;
        }
        //cout << curi << " " << curdif << endl;
        if(v[curi].second == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
