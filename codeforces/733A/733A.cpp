#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s; cin >> s;
    int a = 1, ma = 1;
    s += 'A';
    for(auto u : s)
        if(u == 'A' || u == 'E' || u == 'I' || u == 'O' || u == 'U' || u == 'Y') ma = max(ma, a), a = 1;
        else a++;
    cout << ma << "\n";
}
