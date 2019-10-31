#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        // operator stack
        stack <char> op;

        for(int i = 0; i < n; i++)
        {
            if(isalnum(s[i]))
            {
                cout << s[i];
            }

            if(s[i] == '(')
            {
                op.push(s[i]);
            }

            if(s[i] == ')')
            {
                while(op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }

            if(s[i] ==  '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                op.push(s[i]);
            }
            if(i == n - 1)
            {
                while(!op.empty())
                {
                    cout << op.top();
                    op.pop();
                }
                continue;
            }
        }
        cout << endl;
    }
}
