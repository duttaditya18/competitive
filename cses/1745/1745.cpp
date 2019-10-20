// TLE

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, t;
    vector<int> x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        x.push_back(t);
    }
    int sum = 0;
    sort(x.begin(), x.end());

    set<int> s;

    do
    {
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += x[i];
            //cout << sum << endl;
            s.insert(sum);
        }
        //for(int i = 0; i < n; i++) cout << x[i] << " ";
        //cout << endl;
    }
    while(next_permutation(x.begin(), x.end()));

    set<int>::iterator itr;
    cout << s.size() << endl;
    for(itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}
