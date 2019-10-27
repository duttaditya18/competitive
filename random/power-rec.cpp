#include <bits/stdc++.h>

using namespace std;

int power(int a, int b)
{
    if(b == 0) return 1;
    return a * power(a, b - 1);
}

int main(void)
{
    for(int i = 0; i <= 10; i++) cout << power(2, i) << endl;
}
