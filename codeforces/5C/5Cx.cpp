#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    string s; cin >> s; int n = s.size();
    int x, an = 0, fi = 1;

    int d[n] = {};
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
            d[i] = -1;
        }
        else if(s[i] == ')')
        {
            if(st.size() == 0)
            {
                d[i] = -1;
            }
            else
            {
                x = st.top(); st.pop();
                if(d[x - 1] != -1 && x - 1 >= 0)
                    d[i] = d[x - 1];
                else
                    d[i] = x;
                if(an < i - d[i] + 1)
                {
                    an = i - d[i] + 1;
                    fi = 1;
                }
                else if(an == i - d[i] + 1)
                    fi++;
            }
        }
    }

    // for(int i = 0; i < n; i++) cout << d[i] << " "; cout << "\n";
    cout << an << " " << fi << "\n";
    return 0;
}
