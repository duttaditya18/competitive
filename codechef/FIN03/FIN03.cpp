#include <bits/stdc++.h>

using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    string s, a, b;
    while(getline(cin, s))
    {
        if(s == "END") break;
        stringstream str(s);

        str >> a >> b;
        cout << a << " " << b << "\n";
    }
    return 0;
}
