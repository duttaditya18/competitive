#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(void)
{
    int t, n, x, z;
    bool flagW;
    string s, d;
    cin >> t;
    while(t--)
    {
        d = "";
        flagW = false;
        cin >> s;
        n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(flagW)
            {
                d += s[i];
            }
            if(s[i] == '.')
            {
                flagW = true;
            }
        }

        n = d.size();

        if(n == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            x = stoi(d);
            z = 1;
            // WTF pow() in C++ gives wrong answer
            for(int i = 0; i < n; i++)
            {
                z *= 10;
            }
            cout << z / __gcd(x, z) << endl;
        }
    }
    return 0;
}
