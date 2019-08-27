#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int l = s.size();
    if(((l - 1) % 2) == 1)
    {
        cout << ((l - 1) / 2) + 1 << endl;
        return 0;
    }
    else if(((l - 1) % 2) == 0)
    {
        bool f = true;
        for(int i = 1; i < l; i++)
        {
            if(s[i] == '0')
            {
                continue;
            }
            else
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            cout << ((l - 1) / 2)<< endl;
            return 0;
        }
        else
        {
            cout << ((l - 1) / 2) + 1<< endl;
            return 0;
        }
    }
}
