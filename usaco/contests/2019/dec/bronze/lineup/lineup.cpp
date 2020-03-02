#include <bits/stdc++.h>

using namespace std;

vector<string> cow = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<int> v[8];

int main(void)
{
    ifstream cin("lineup.in");
    ofstream cout("lineup.out");

    map<string, int> m;
    for(int i = 0; i < 8; i++) m[cow[i]] = i;

    int n; cin >> n;

    string a, s, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> s >> s >> s >> s >> b;
        if(!count(v[m[a]].begin(), v[m[a]].end(), m[b]))
        {
            v[m[a]].push_back(m[b]);
            v[m[b]].push_back(m[a]);
        }
    }

    do
    {
        bool f = true;
        for(int i = 0; i < 8; i++)
        {
            for(auto x : v[m[cow[i]]])
            {
                if(i == 0)
                {
                    if(!(m[cow[i + 1]] == x))
                    {
                        f = false;
                        break;
                    }
                }
                else if(i == 7)
                {
                    if(!(m[cow[i - 1]] == x))
                    {
                        f = false;
                        break;
                    }
                }
                else if(!(m[cow[i - 1]] == x || m[cow[i + 1]] == x))
                {
                    f = false;
                    break;
                }
            }
        }
        if(f)
        {
            for(int i = 0; i < 8; i++) cout << cow[i] << "\n";
            break;
        }
    } while(next_permutation(cow.begin(), cow.end()));
}
