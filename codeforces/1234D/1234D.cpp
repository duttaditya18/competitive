#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // ofstream cout("output.txt");
    string s;
    cin >> s;

    // a - 0, ..., z - 25
    vector<set<int>> v(26);

    for(int i = 0, l = s.size(); i < l; i++)
    {
        v[s[i] - 'a'].insert(i);
    }

    // for(set<int>::iterator itr = v[1].begin(); itr != v[1].end(); itr++) cout << *itr << " "; cout << endl;

    int q;
    cin >> q;

    int t;

    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;

            pos--;
            v[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            v[c - 'a'].insert(pos);
        }
        else if(t == 2)
        {
            int l, r, cnt = 0;
            cin >> l >> r;
            l--;

            for(int i = 0; i < 26; i++)
            {
                auto itr = v[i].lower_bound(l);
                if(itr != v[i].end() && *itr < r)
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
}
