#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    string s = "";
    do
    {
        if(n % 2)
        {
            s = '1' + s;
            n--;
        }
        else s = '0' + s;

        n = (n / (-2));
    } while(n != 0);
    cout << s << "\n";
}
