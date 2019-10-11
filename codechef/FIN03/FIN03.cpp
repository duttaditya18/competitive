#include <bits/stdc++.h>

using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    string str;
    getline (cin, str);
    while(str != "END")
    {
        int x = stoi(str.substr(0, str.find(' ')));
        int y = stoi(str.substr(str.find(' ') + 1, str.size() - str.find(' ') + 1));
        //cout << x << " " << y << endl;
        getline (cin, str);
    }
}
