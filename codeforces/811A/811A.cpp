#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    int x = sqrt(a);
    if(b >= (x * x + x)) cout << "Vladik";
    else cout << "Valera";
    cout << "\n";

    return 0;
}
