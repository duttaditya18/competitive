#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int tm;
        cin >> tm;
        // Calculating Prefix of differences of a[] and b[]
        int prf[n];
        prf[0] = a[0] - tm;
        for(int i = 1; i < n; i++)
        {
            cin >> tm;
            prf[i] = a[i] - tm;
            prf[i] += prf[i - 1];
        }
        /*for(int i = 0; i < n; i++) cout << prf[i] << " ";
        cout << endl;*/

        unordered_map<int, int> mp;
        int ma = 0;
        for(int i = 0; i < n; i++)
        {
            if(prf[i] == 0)
            {
                ma = i + 1;
            }
            else if(!mp.count(prf[i]))
            {
                mp[prf[i]] = i;
            }
            else if(mp.count(prf[i]))
            {
                ma = max(ma, i - mp[prf[i]]);
            }
        }


    /*unordered_map<int, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
      cout << itr->first << "  " << itr->second << endl;
    }*/
        cout << ma << endl;
    }
    return 0;
}
