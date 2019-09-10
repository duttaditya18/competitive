#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int l, s;
    cin >> l >> s;

    if(((9*l) < s) || ((s == 0) && (l > 1)))
    {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    if(l == 1 and s == 0)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    string bg = "", sm = "";
    int x = (s / 9);
    bool f = ((s % 9) ? true : false);

    // Calculating big
    for(int i = 0; i < x; i++)
    {
        bg += "9";
    }
    if(f) bg += to_string(s % 9);

    string bgs = bg;
    int bgz = bgs.size();

    for(int i = bgz; i < l; i++)
    {
        bg += "0";
    }

    if(bgz < l)
    {
        sm += "1";
        string ed = bgs.substr((bgs.size() - 1), 1);
        bgs.pop_back();
        ed = to_string(stoi(ed) - 1);
        bgs += ed;
    }
    reverse(bgs.begin(), bgs.end());
    for(int i = 0; i < (l - bgz - 1); i++)
    {
        sm += "0";
    }
    sm += bgs;
    cout << sm << " " << bg << endl;
    return 0;
}
