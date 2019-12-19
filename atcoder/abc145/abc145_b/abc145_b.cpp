#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    int n;
    cin >> n;

    cin >> s;

    if(n % 2)
    {
        cout << "No" << endl;
        return 0;
    }

    if(s.substr(0, n / 2) == s.substr(n / 2, n / 2))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
