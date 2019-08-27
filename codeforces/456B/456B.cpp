#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    if(s == "0")
    {
        cout << 4 << endl;
        return 0;
    }
    string c;
    if(s.size() < 2)
        c = s.substr(s.size() - 1, 1);
    else
        c = s.substr(s.size() - 2, 2);

    s.erase();

    int a2[4] = {6, 2, 4, 8};
    int a3[4] = {1, 3, 9, 7};
    int a4[3] = {6, 4};

    int x = stoi(c);
    cout << (a2[x % 4] + a3[x % 4] + a4[x % 2] + 1) % 5;
    return 0;

}
