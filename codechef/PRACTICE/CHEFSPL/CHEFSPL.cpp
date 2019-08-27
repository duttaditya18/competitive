// TLE on 2 Tasks

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        int l = s.length();
        bool ans = false;
        if(l < 2)
        {
            ans = false;
        }
        else if ((l % 2) == 0)
        {
            if (s.substr(0, l/2) == s.substr(l/2,l/2))
            {
                ans = true;
            }
        }
        else
        {
            for(int i = 0; i < l; i++)
            {
                string x = s;
                x.erase(i, 1);
                if(x.substr(0, (l - 1) / 2) == x.substr((l - 1) / 2, l))
                {
                    ans = true;
                    break;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
