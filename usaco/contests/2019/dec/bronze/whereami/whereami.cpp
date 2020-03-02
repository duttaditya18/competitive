#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream cin("whereami.in");
    ofstream cout("whereami.out");

    int n; cin >> n;
    string s; cin >> s;

    unordered_set<string> st;

    int i;
    for(i = 1; i <= n; i++)
    {
        bool f = true;
        for(int j = 0; j <= n - i; j++)
        {
            if(!st.count(s.substr(j, i)))
                st.insert(s.substr(j, i));
            else
            {
                f = false;
                break;
            }
        }
        if(f) break;
    }
    cout << i << "\n";
    return 0;
}
