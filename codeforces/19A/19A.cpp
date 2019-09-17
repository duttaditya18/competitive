#include <bits/stdc++.h>

using namespace std;

string s[55];
map <string, int> pnts, gdif, gls;
bool comparator(string s1, string s2)
{
    if(pnts[s1] != pnts[s2]) return pnts[s1] > pnts[s2];
    if(gdif[s1] != gdif[s2]) return gdif[s1] > gdif[s2];
    return gls[s1] > gls[s2];
}

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    string t1, t2;
    // names of teams
    string t1x, t2x;
    // number of goals scored
    int g1, g2;
    for(int i = 0; i < (n*(n - 1)/2); i++)
    {
        cin >> t1 >> t2;
        // STL > PYTHON3. FUCK YOU PYTHON
        t1x = t1.substr(0, (t1.find("-")));
        t2x = t1.substr((t1.find("-") + 1), (t1.size() - ((t1.find("-") + 1))));
        g1 = stoi(t2.substr(0, (t2.find(":"))));
        g2 = stoi(t2.substr((t2.find(":") + 1), (t2.size() - ((t2.find(":") + 1)))));
        if(g1 > g2)
        {
            pnts[t1x]+= 3;
        }
        else if(g2 > g1)
        {
            pnts[t2x] += 3;
        }
        else if(g1 == g2)
        {
            pnts[t1x]++;
            pnts[t2x]++;
        }
        gdif[t1x] += (g1 - g2);
        gdif[t2x] += (g2 - g1);
        gls[t1x] += g1;
        gls[t2x] += g2;
    }

    sort(s, s + n, comparator);
    sort(s, s + (n / 2));

    for(int i = 0; i < (n / 2); i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}

